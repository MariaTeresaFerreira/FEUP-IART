import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Vector;

public class Minimax {
    public static Game gameInitial;
    public static int depthMax = 5;
    public static int chosenPlay = -1;

    Minimax(Game game){
        this.gameInitial = game;
    }

    public int makeDecision(Board state) {
        int result = 0;
        int resultValue = Integer.MIN_VALUE;
        int player = state.getActivePlayer();
        for (int action : state.getValidTranslatedMoves()) {
            
            for(int i = 0; i < 10; i++)
                System.out.println("Olá");

            int value = minValue(state.getResult(state, translate(action,state.getActivePlayer())), player, depthMax);

            if (value > resultValue) {
                result = action;
                resultValue = value;
            }
        }
        
        System.out.println("Result: " + result);
        return result;
    }

    public int maxValue(Board state, int player, int depth) { // returns an utility
        // value
        System.out.println("Max -> Depth: " + depth);
        if (state.getGameOver() || depth == 0){
            return state.getBoardScore();
        }
        int value = Integer.MIN_VALUE;

        for (int action : state.getValidTranslatedMoves()){
            System.out.println("max -> action: " + action);
            state.draw();
            //state.getResult(state, translate(action,state.getActivePlayer())).draw();
            if(state.getResult(state, translate(action,state.getActivePlayer())).getPlayAgain())
                value = Math.max(value, maxValue(state.getResult(state, translate(action,state.getActivePlayer())), player, depth - 1));
            else
                value = Math.min(value, minValue(state.getResult(state, translate(action,state.getActivePlayer())), player, depth - 1));
        }
        return value;
    }

    public int minValue(Board state, int player, int depth) { // returns an utility
        // value
        System.out.println("Min -> Depth: " + depth);
        if (state.getGameOver() || depth == 0)
            return state.getBoardScore();
        int value = Integer.MAX_VALUE;

        for (int action : state.getValidTranslatedMoves()){
            System.out.println("min -> action: " + action);
            state.draw();
            //state.getResult(state, translate(action,state.getActivePlayer())).draw();
            if(state.getResult(state, translate(action,state.getActivePlayer())).getPlayAgain())
                value = Math.min(value, minValue(state.getResult(state, translate(action,state.getActivePlayer())), player, depth - 1));
            else
                value = Math.max(value, maxValue(state.getResult(state, translate(action,state.getActivePlayer())), player, depth - 1));
        }
        return value;
    }


 public int translate(int i, int player) {
        int j = -1;

        if(player == 0){
            switch(i) {
                case 1:
                    j = 5;
                    break;
                case 2:
                    j = 4;
                    break;
                case 3:
                    j = 3;
                    break;
                case 4:
                    j = 2;
                    break;
                case 5:
                    j = 1;
                    break;
                case 6:
                    j = 0;
                    break;
            }
        }

        if(player == 1){
            switch(i) {
                case 1:
                    j = 0;
                    break;
                case 2:
                    j = 1;
                    break;
                case 3:
                    j = 2;
                    break;
                case 4:
                    j = 3;
                    break;
                case 5:
                    j = 4;
                    break;
                case 6:
                    j = 5;
                    break;
            }
        }
        if(j == -1){
            System.out.println("input error");
        }

        return j;
    }

}