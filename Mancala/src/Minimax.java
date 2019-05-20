import java.util.List;
import java.util.Vector;

public abstract class Minimax {
    private Tree tree;

    public void constructTree(Board b){
        Node root = new Node(b);
        tree = new Tree(root);
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

}
