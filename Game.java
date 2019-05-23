import java.io.IOException;
import java.sql.SQLOutput;
import java.util.Scanner;

import java.io.InputStreamReader;
import java.util.Vector;


public class Game {

    private Board board;
    private int mode = 0;
    private Scanner in;
    public static int depthMax = 1;


    public Game() throws IOException {
        board = new Board();
        in = new Scanner(System.in);
    }

    private void draw(){
        for(int i = 0; i < 5; i++){
            System.out.println();
        }

        board.draw();

    }

    public void run() throws IOException {

        while(mode < 1 || mode > 3) {
            System.out.println("Insert the mode of the game you want to play:");
            System.out.println("1 for Human vs Human");
            System.out.println("2 for Human vs AI");
            System.out.println("3 for AI vs AI");

            int mode = in.nextInt();

            if (mode == 1) {
                humanVsHuman();
            } else if (mode == 2) {
                humanVsAI();
            } else if (mode == 3) {
                aIVsAI();
            }
        }
    }

    private void humanVsHuman() throws IOException {

        while (!board.getGameOver()){

            this.draw();

            System.out.println("Player " + (board.getActivePlayer() + 1 ) + ", Insert the column you want to play between 1 and 6:");
            int mov = in.nextInt();

            this.board = board.getResult(this.board,translateInput(mov, board.getActivePlayer()));
        }
    }

    private void humanVsAI() throws IOException {

        while (!board.getGameOver()){

            this.draw();

            //move(column);

            this.draw();

            //AI move
        }
    }

    private void aIVsAI() throws IOException {

        while (!board.getGameOver()){
 
            this.draw();

            System.out.println("IA " + (board.getActivePlayer() + 1 ) + ": ");
            int mov = makeDecision(board);

            this.board = board.getResult(this.board,translateInput(mov, board.getActivePlayer()));

            in.nextLine();
        }
    }

    public int translateInput(int i, int player) {
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

    public Board getBoard() {
        return board;
    }


    public int makeDecision(Board sta) {
        int result = 0;
        int resultValue = 0;
        int value = 0;
        Board state = new Board(sta);

        for (int action : state.getValidMoves()) {
            Board b = new Board(state.getResult(state, action));
            //System.out.println("Action: " + action);
            //b.draw();

            if(state.getActivePlayer() == 1){

                value = minValue(b, depthMax - 1);
                if(resultValue == 0)
                    resultValue = Integer.MAX_VALUE;

                if (value < resultValue) {
                    result = action;
                    resultValue = value;
                }
            }
            else{

                value = maxValue(b, depthMax - 1);
                if(resultValue == 0)
                    resultValue = Integer.MIN_VALUE;

                if (value > resultValue) {
                    result = action;
                    resultValue = value;
                }
            }
        }
        
        System.out.println("Result: " + result);
        return result;
    }

    public int maxValue(Board sta, int depth) {
        Board state = new Board(sta);
        Board b;
        //System.out.println("Max Depth: " + depth + " ActivePlayer: " + state.getActivePlayer());

        if (state.getGameOver() || depth == 0){
            System.out.println("Score Max: " + state.getBoardScore());
            return state.getBoardScore();
        }
        int value = Integer.MIN_VALUE;

        for (int action : state.getValidMoves()){
            b = new Board(state.getResult(state, translateInput(action, state.getActivePlayer()) ));
            //System.out.println("Max Action: " + action);
           // b.draw();

            if(b.getActivePlayer() == 1)
                value = Math.min(value, minValue(b, depth - 1));
            else
                value = Math.max(value, maxValue(b, depth - 1));

        }
        System.out.println("Value: " + value);
        return value;
    }

    public int minValue(Board sta, int depth) {
        Board state = new Board(sta);
        Board b;
        //System.out.println("Min Depth: " + depth + " ActivePlayer: " + state.getActivePlayer());

        if (state.getGameOver() || depth == 0){
            System.out.println("Score Min: " + state.getBoardScore());
            return state.getBoardScore();
        }
        int value = Integer.MAX_VALUE;

        for (int action : state.getValidMoves()){
            b = new Board(state.getResult(state, translateInput(action, state.getActivePlayer()) ));
            //System.out.println("Min Action: " + action);
            //b.draw();

            if(b.getActivePlayer() == 1)
                value = Math.min(value, minValue(b, depth - 1));
            else
                value = Math.max(value, maxValue(b, depth - 1));
        }
        return value;
    }
}