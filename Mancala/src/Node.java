import java.util.List;

public class Node {
    public Board board;
    public int lastPlayer;
    public int lastMove;
    public int boardScore;
    public boolean isRoot;
    public List<Node> children;

    public Node(Board board) {
        this.board = board;
        this.lastPlayer = -1;
        this.lastMove = -1;
        this.boardScore = this.board.getBoardScore();
        this.isRoot = true;

    }

    public Node(Board board, int lastPlayer, int lastMove) {
        this.board = board;
        this.lastPlayer = lastPlayer;
        this.lastMove = lastMove;
        this.boardScore = this.board.getBoardScore();
        this.isRoot = false;
    }

    public void addChild(Node n){
        children.add(n);
    }
}