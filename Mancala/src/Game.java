import java.io.IOException;
import java.sql.SQLOutput;
import java.util.Scanner;

import java.io.InputStreamReader;
import java.util.Vector;


public class Game {

    private Board board;
    private int mode = 0;
    private Scanner in;


    public Game() throws IOException {
        board = new Board();
        in = new Scanner(System.in);
    }

    private void draw() {
        /*for(int i = 0; i < 10; i++){
            System.out.println();
        }*/

        board.draw();

    }

    public void run(int mode) throws IOException {

        if (mode == 1) {
            humanVsHuman();
        } else if (mode == 2) {
            humanVsAI();
        } else if (mode == 3) {
            aIVsAI();
        } else
            System.out.println("error");
    }

    private void humanVsHuman() throws IOException {

        while (!board.getGameOver()) {

            this.draw();
            int mov = getMoveFromUser(board.getActivePlayer());

            board.move(translateInput(mov, board.getActivePlayer()));
        }
    }

    private void humanVsAI() throws IOException {

        int move;

        while (!board.getGameOver()) {
            this.draw();

            if(board.getActivePlayer() == 0){ // HUMAN PLAY
                move = getMoveFromUser(0);
                board.move(translateInput(move, board.getActivePlayer()));

            }else{
                move = getMoveFromAI();
                board.move(translateInput(move, board.getActivePlayer()));
                System.out.println("Move: " + move);
            }



        }
    }

    private void aIVsAI() throws IOException {

        this.draw();
        while (!board.getGameOver()) {

            int play = getMoveFromAI();

            board.move(play);

            System.out.println("Active player: " + (board.getActivePlayer() + 1));
            System.out.println("Move: " + play);

            board.draw();

        }

        if (board.getBoardScore() < 0) {
            System.out.println("Player 2 won!");
        } else if (board.getBoardScore() > 0) {
            System.out.println("Player 1 won!");
        } else if (board.getBoardScore() == 0) {
            System.out.println("Its a tie!");
        } else {
            System.out.println("Error");
        }

        System.out.println("node number: " + Minimax.nodeCounter);
    }

    private int translateInput(int i, int player) { //de 1 a 6 para 0 a 5
        int j = -1;

        if (player == 0) {
            switch (i) {
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
                default:
                    System.out.println("input error");
            }
        }

        if (player == 1) {
            switch (i) {
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
        if (j == -1) {
            System.out.println("input error");
        }

        return j;
    }

    private static int translateHint(int i, int player) { //de 0 a 5 para 1 a 6
        int j = -1;

        if(player == 0){
            switch(i) {
                case 5:
                    j = 1;
                    break;
                case 4:
                    j = 2;
                    break;
                case 3:
                    j = 3;
                    break;
                case 2:
                    j = 4;
                    break;
                case 1:
                    j = 5;
                    break;
                case 0:
                    j = 6;
                    break;
                default:
                    System.out.println("input error");
            }
        }

        if(player == 1){
            switch(i) {
                case 0:
                    j = 1;
                    break;
                case 1:
                    j = 2;
                    break;
                case 2:
                    j = 3;
                    break;
                case 3:
                    j = 4;
                    break;
                case 4:
                    j = 5;
                    break;
                case 5:
                    j = 6;
                    break;
            }
        }
        if(j == -1){
            System.out.println("input error");
        }

        return j;
    }

    public int getMoveFromUser(int player){
        String input;
        while(true){
            System.out.println("Player " + (board.getActivePlayer() + 1) + ", Insert the column you want to play between 1 and 6 (or h for help):");
            input = in.next();
            if (input.equals("h")) {
                Minimax.constructTree(board);
                int play = translateHint(Minimax.getTreeBoardScores()[1], player);
                System.out.println("Hint: " + play);
            } else if (input.equals("1") || input.equals("2") || input.equals("3") || input.equals("4") || input.equals("5") || input.equals("6")) {
                break;
            } else
                System.out.println("Please enter a valid option");
        }

        return Integer.parseInt(input);
    }

    public int getMoveFromAI(){
        Minimax.constructTree(board);
        int play = Minimax.getTreeBoardScores()[1];
        return play;
    }
}
