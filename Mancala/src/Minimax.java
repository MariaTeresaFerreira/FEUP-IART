import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Vector;

public class Minimax {
    public static Tree tree;
    public static int depthMax = 5;
    public static int chosenPlay = -1;

    public static int counter = 0;

    public static void constructTree(Board b){
        Node root = new Node(b);
        tree = new Tree(root);
        constructTree(root, 0);
    }

    public static void constructTree(Node parent, int depth){
        if(depth < depthMax){
            Vector<Integer> possiblePlays = parent.board.getValidMoves();

            /*System.out.print("valid moves :");

            for(int i = 0; i < possiblePlays.size(); i++){
                System.out.print(possiblePlays.get(i) + " -> ");
            }
            System.out.println();
            */

            for(Integer play : possiblePlays){
                Board newBoard = new Board(parent.board);
                newBoard.move(play);
                Node newNode = new Node(newBoard, parent.board.getActivePlayer(), play);
                parent.addChild(newNode);
                if(!newBoard.getGameOver()){
                    constructTree(newNode, depth+1);
                }
            }
        }
    }

    public static int getTreeBoardScores(){
        Node root = tree.getRoot();
        return getTreeBoardScores(root);
    }

    private static int getTreeBoardScores(Node parent) {
        
        List<Node> children = parent.children;

        if(parent.board.getActivePlayer() == 0){ //max
            int chosenValue = 10;
            for(Node child : children){
                int currValue;
                 // é folha
                    child.inheritedScore = child.boardScore;
                    currValue = child.inheritedScore;
                

                if(currValue > chosenValue){
                    chosenValue = currValue;
                    chosenPlay = child.lastMove;
                }

            }
            return chosenValue;
        } else {
            int chosenValue = -10;
            for(Node child : children){
                int currValue;
                 // é folha
                    child.inheritedScore = child.boardScore;
                    currValue = child.inheritedScore;
                

                if(currValue < chosenValue){
                    chosenValue = currValue;
                    chosenPlay = child.lastMove;
                }

            }
            return chosenValue;
        }
    }
}