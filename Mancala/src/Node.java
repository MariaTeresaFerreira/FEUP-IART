public class Node {
    public Node parent;
    public Board board;
    public int lastPlayer;
    public int lastMove;
    public int boardScore;
    public boolean isRoot;

    public Node(Board board, int lastPlayer, int lastMove, int boardScore) {
        this.board = board;
        this.lastPlayer = lastPlayer;
        this.lastMove = lastMove;
        this.boardScore = this.board.getBoardScore();
        this.isRoot = true;

    }

    public Node(Node parent, Board board, int lastPlayer, int lastMove) {
        this.parent = parent;
        this.board = board;
        this.lastPlayer = lastPlayer;
        this.lastMove = lastMove;
        this.boardScore = this.board.getBoardScore();
        this.isRoot = false;
    }
}
