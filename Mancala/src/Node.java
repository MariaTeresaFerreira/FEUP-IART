import java.util.List;
import java.util.Vector;

public class Node {
    public Board board;
    public int lastPlayer; //parent player
    public int lastMove;
    public int boardScore;
    public Vector<Node> children;
    public int inheritedScore;

    public Node(Board board) {
        children = new Vector<>();
        this.board = board;
        this.lastPlayer = -1;
        this.lastMove = -1;
        this.boardScore = this.board.getBoardScore();
        this.inheritedScore = -1;

    }

    public Node(Board board, int lastPlayer, int lastMove) {
        children = new Vector<>();
        this.board = board;
        this.lastPlayer = lastPlayer;
        this.lastMove = lastMove;
        this.boardScore = this.board.getBoardScore();
        this.inheritedScore = -1;

    }

    public void addChild(Node n){
        children.add(n);
    }
}
