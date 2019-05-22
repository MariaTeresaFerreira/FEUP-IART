import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Vector;

public class Minimax {
    public static Tree tree;
    public static int depthMax = 5;

    public static void constructTree(Board b){
        Node root = new Node(b);
        tree = new Tree(root);
        constructTree(root, 0);
    }

    public static void constructTree(Node parent, int depth){
        if(depth < depthMax){
            Vector<Integer> possiblePlays = parent.board.getValidMoves();
            possiblePlays.forEach(play -> {
                Board newBoard = new Board(parent.board);
                //newBoard.move(newBoard.getActivePlayer(), play);
                Node newNode = new Node(newBoard, parent.board.getActivePlayer(), play);
                parent.addChild(newNode);
                if(!newBoard.getGameOver()){
                    constructTree(newNode, depth+1);
                }
            });
        }
    }

    public static int getTreeBoardScores(){
        Node root = tree.getRoot();
        return getTreeBoardScores(root);
    }

    private static int getTreeBoardScores(Node parent) {
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
}