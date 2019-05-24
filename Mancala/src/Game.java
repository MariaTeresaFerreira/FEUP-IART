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

        System.out.println("mode: " + mode);
        System.out.println("depth: " + Minimax.depthMax);
        System.out.println("alpha beta: " + Minimax.alphaBeta);
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
            while(true){
                System.out.println("Hint?: (y/n)");
                String hint = in.next();
                if (hint.equals("y")) {
                    Minimax.constructTree(board);
                    int play = Minimax.getTreeBoardScores()[1];
                    System.out.println("hint: " + play);
                    break;
                } else if (hint.equals("n")) {
                    break;
                } else
                    System.out.println("Please enter a valid option");
            }



            System.out.println("Player " + (board.getActivePlayer() + 1) + ", Insert the column you want to play between 1 and 6:");
            int mov = in.nextInt();

            board.move(translateInput(mov, board.getActivePlayer()));
        }
    }

    private void humanVsAI() throws IOException {

        while (!board.getGameOver()) {

            this.draw();

            //move(column);

            this.draw();

            //AI move
        }
    }

    private void aIVsAI() throws IOException {

        this.draw();
        while (!board.getGameOver()) {

            System.out.println("\n");

            Minimax.constructTree(board);
            int play = Minimax.getTreeBoardScores()[1];

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

        System.out.println("i: " + i);

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
}
