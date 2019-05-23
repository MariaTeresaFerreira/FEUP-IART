import java.util.Comparator;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.Vector;

public class Minimax {
    public static Game game;
    public static int depthMax = 5;
    public static int chosenPlay = -1;

    Minimax(Game game){
        this.game = game;

    }


    public int makeDecision(Board state) {
        int result = 0;
        int resultValue = Integer.MIN_VALUE;
        int player = game.getBoard().getActivePlayer();
        for (int action : game.getBoard().getValidTranslatedMoves()) {
            int value = minValue(game.getBoard().getResult(state, action), player);
            if (value > resultValue) {
                result = action;
                resultValue = value;
            }
        }
        return result;
    }

    public int maxValue(Board state, int player) { // returns an utility
        // value
        if (game.getBoard().getGameOver())
            return game.getBoard().getBoardScore();
        int value = Integer.MIN_VALUE;

        for (int action : game.getBoard().getValidTranslatedMoves()){
            if(game.getBoard().getResult(state, action).getPlayAgain())
                value = Math.max(value,maxValue(game.getBoard().getResult(state, action), player));
            else
                value = Math.min(value,minValue(game.getBoard().getResult(state, action), player));
        }
            
        return value;
    }

    public int minValue(Board state, int player) { // returns an utility
        // value
        if (game.getBoard().getGameOver())
            return game.getBoard().getBoardScore();
        int value = Integer.MAX_VALUE;

        for (int action : game.getBoard().getValidTranslatedMoves()){
            if(game.getBoard().getResult(state, action).getPlayAgain())
                value = Math.min(value,minValue(game.getBoard().getResult(state, action), player));
            else
                value = Math.max(value,maxValue(game.getBoard().getResult(state, action), player));
        }
    return value;
    }



}