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
        /*for(int i = 0; i < 10; i++){
            System.out.println();
        }*/

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

        this.draw();
        while (!board.getGameOver()){

            System.out.println("\n");

            Minimax.constructTree(board);
            int score = Minimax.getTreeBoardScores()[0];
            int play = Minimax.getTreeBoardScores()[1];

            /*
            System.out.println("active player: " + board.getActivePlayer());
            System.out.println("chosen play: " + play);
            System.out.println("board score: " + score);
            Vector<Integer> possiblePlays = board.getValidMoves();

            System.out.print("valid moves: ");

            for(int i = 0; i < possiblePlays.size(); i++){
                System.out.print(possiblePlays.get(i) + " -> ");
            }
            System.out.print("\n");*/

            board.move(play);

            board.draw();

        }

        if(board.getBoardScore() < 0){
            System.out.println("Player 2 won!");
        }else if(board.getBoardScore() > 0){
            System.out.println("Player 1 won!");
        }else if(board.getBoardScore() == 0){
            System.out.println("Its a tie!");
        }else{
            System.out.println("Error");
        }
    }

    private int translateInput(int i, int player) { //de 1 a 6 para 0 a 5
        int j = -1;

        System.out.println("i: " + i);

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
                default:
                    System.out.println("input error");
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
