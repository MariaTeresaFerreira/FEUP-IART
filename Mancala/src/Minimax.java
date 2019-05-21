import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Vector;

public abstract class Minimax {
    private Tree tree;

    public void constructTree(Board b){
        Node root = new Node(b);
        this.tree = new Tree(root);
        constructTree(root);
    }

    protected void constructTree(Node parent){
        Vector<Integer> possiblePlays = parent.board.getValidMoves();
        int activePlayer = parent.board.getActivePlayer();
        possiblePlays.forEach(n -> {
            Board newBoard = parent.board;
            newBoard.move(activePlayer, n);
            if(!newBoard.getGameOver()){
            Node newNode = new Node(newBoard, activePlayer, n);
            parent.addChild(newNode);
            if(newBoard.getValidMoves().size() > 0)
                constructTree(newNode);
            }
        });

    }

    public boolean checkWin(){
        Node root = this.tree.getRoot();
        checkWin(root);
        return root.inheritedScore == 1;
    }

    public void checkWin(Node parent){
        List<Node> children = parent.children;
        children.forEach(child -> {
            if(child.board.getGameOver()){
                if(child.board.getBoardScore() > 0)
                    child.inheritedWinner = 1;
                else if(child.board.getBoardScore() < 0)
                    child.inheritedWinner = -1;
                else if(child.board.getBoardScore() == 0)
                    child.inheritedWinner = 0;
            } else
                checkWin(child);
        });

        Node bestChild= findBestChild(parent.board.getActivePlayer(), children); //TODO verificar isto
        parent.inheritedScore = bestChild.inheritedScore;

    }

    private Node findBestChild(int activePlayer, List<Node> children) {
        Comparator<Node> byScoreComparator = new scoreComparator();
        boolean maxPlayer;
        if(activePlayer == 0)
            maxPlayer = true;
        else
            maxPlayer = false;
        return children.stream().max(maxPlayer ? byScoreComparator : byScoreComparator.reversed()).orElseThrow(NoSuchElementException::new);

    }



}

class scoreComparator implements Comparator<Node> {
    @Override
    public int compare(Node firstNode, Node secondNode) {
        return (firstNode.inheritedScore - secondNode.inheritedScore);
    }
}