import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Vector;

public abstract class Minimax {
    private Tree tree;
    private int depthCounter;

    public void constructTree(Board b, int depth){
        Node root = new Node(b);
        this.tree = new Tree(root);
        constructTree(root, depth);
    }

    public void constructTree(Node parent, int depth){
        depthCounter = 0;
        if(depth < depthCounter){
            Vector<Integer> possiblePlays = parent.board.getValidMoves();
            possiblePlays.forEach(play -> {
                Board newBoard = new Board(parent.board);
                newBoard.move(newBoard.getActivePlayer(), play);
                Node newNode = new Node(newBoard, parent.board.getActivePlayer(), play);
                parent.addChild(newNode);
                if(!newBoard.getGameOver()){
                    depthCounter++; //TODO: isto esta mal, ver como contar a depth
                    constructTree(newNode, depth);
                }
            });
        }
    }

    public int getTreeBoardScores(){
        Node root = this.tree.getRoot();
        return getTreeBoardScores(root);
    }

    private int getTreeBoardScores(Node parent) {
        List<Node> children = parent.children;
        if(parent.board.getActivePlayer() == 0){ //max
            int chosenValue = Integer.MIN_VALUE;
            for(Node child : children){
                int currValue;
                if(child.board.getGameOver() || child.children.size() == 0){ // é folha
                    child.inheritedScore = child.boardScore;
                    currValue = child.inheritedScore;
                } else{
                    currValue = getTreeBoardScores(child);
                }

                if(currValue > chosenValue)
                    chosenValue = currValue;
            }
            return chosenValue;
        } else {
            int chosenValue = Integer.MAX_VALUE;
            for(Node child : children){
                int currValue;
                if(child.board.getGameOver() || child.children.size() == 0){ // é folha
                    child.inheritedScore = child.boardScore;
                    currValue = child.inheritedScore;
                } else{
                    currValue = getTreeBoardScores(child);
                }

                if(currValue < chosenValue)
                    chosenValue = currValue;
            }
            return chosenValue;
        }



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