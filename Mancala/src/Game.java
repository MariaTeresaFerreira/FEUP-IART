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

    private void draw(){
        for(int i = 0; i < 10; i++){
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

            board.move(translateInput(mov, board.getActivePlayer()));
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
            Minimax.constructTree(board);
            int score = Minimax.getTreeBoardScores();

            System.out.println("score: " + score);
            System.out.println();
            
            System.out.println("move: " + Minimax.chosenPlay);
            board.move(Minimax.chosenPlay);

            board.draw();

            in.next();
        }
    }

    private int translateInput(int i, int player) {
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
