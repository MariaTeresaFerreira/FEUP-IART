import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Vector;

public class Minimax {
    public static Tree tree;
    public static int depthMax = 5;
    public static int nodeCounter = 0;
    public static boolean alphaBeta = false;


    public static int counter = 0;

    public static void constructTree(Board b){
        Node root = new Node(b);
        tree = new Tree(root);
        constructTree(root, 0);
    }

    public static void constructTree(Node parent, int depth){
        if(depth < depthMax){
            Vector<Integer> possiblePlays = parent.board.getValidMoves();

            for(int i = 0; i < possiblePlays.size(); i++){
                Board newBoard = new Board(parent.board);
                newBoard.move(possiblePlays.elementAt(i));
                Node newNode = new Node(newBoard, parent.board.getActivePlayer(), possiblePlays.elementAt(i));
                parent.addChild(newNode);
                if(!newBoard.getGameOver()){
                    constructTree(newNode, depth+1);
                }

            }
        }
    }

    public static int[] getTreeBoardScores(){
        Node root = tree.getRoot();
        return getTreeBoardScores(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }

    private static int[] getTreeBoardScores(Node parent, int alpha, int beta) {
        nodeCounter++;
        List<Node> children = parent.children;
        int[] sol = new int[2]; //score, play
        int bestPlay = -1;


        if(parent.board.getActivePlayer() == 0){ //max

            int chosenValue = Integer.MIN_VALUE;
            for(Node child : children){
                int[] currValue = new int[2];
                if(child.board.getGameOver() || child.children.size() == 0){ // é folha
                    child.inheritedScore = child.boardScore;
                    currValue[0] = child.inheritedScore;
                } else {
                    currValue = getTreeBoardScores(child, alpha, beta);
                }

                if(currValue[0] >= chosenValue){
                    chosenValue = currValue[0];
                    bestPlay = child.lastMove;
                }

                //ALPHABETA - BEGIN
                if(alphaBeta){
                    alpha = Math.max(alpha, chosenValue);
                    if(alpha <= beta)
                        break;
                }
                //ALPHABETA - END

            }
            sol[0] = chosenValue;
            sol[1] = bestPlay;
            return sol;
        } else {                                      //min
            int chosenValue = Integer.MAX_VALUE;
            for(Node child : children){
                int[] currValue = new int[2];
                if(child.board.getGameOver() || child.children.size() == 0){ // é folha
                    child.inheritedScore = child.boardScore;
                    currValue[0] = child.inheritedScore;
                } else{
                    currValue = getTreeBoardScores(child, alpha, beta);
                }

                if(currValue[0] <= chosenValue){
                    chosenValue = currValue[0];
                    bestPlay = child.lastMove;
                }

                //ALPHABETA - BEGIN
                if(alphaBeta) {
                    beta = Math.max(beta, chosenValue);
                    if (beta <= alpha)
                        break;
                }
                //ALPHABETA - END

            }
            sol[0] = chosenValue;
            sol[1] = bestPlay;
            return sol;
        }
    }


}