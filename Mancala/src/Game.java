import java.io.IOException;
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
            int mov = in.nextInt();

            board.move(mov);

        }
    }

    private void humanVsAI() throws IOException {

        while (!board.getGameOver()){

            this.draw();

            completeMove(0,in);

            this.draw();

            //AI move
        }
    }

    private void aIVsAI() throws IOException {

        while (!board.getGameOver()){

            this.draw();
            Minimax.constructTree(board);
            int move = Minimax.getTreeBoardScores();
            //completeMove(move);

            in.next();
            //AI move

            this.draw();

            in.next();
            //AI move
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

    void completeMove(int player, Scanner in){

        while (true){
            System.out.println("current board score: " + board.getBoardScore());
            System.out.println("Player " + (player + 1 ) + ", Insert the column you want to play between 1 and 6:");


            System.out.print("valid moves :");
            for(int i = 0; i < board.getValidTranslatedMoves().size(); i++){
                System.out.print(board.getValidMoves().get(i));
            }
            System.out.println();
            System.out.print("valid moves size:");
            System.out.println(board.getValidTranslatedMoves().size());

            int a = translateInput(in.nextInt(), board.getActivePlayer());
            if(board.move(a)) {
                break;
            }
            draw();
        }

    }
/*
    void completeMove(int move){
        int a = translateInput(in.nextInt(), board.getActivePlayer());
        if(board.move(a)) {
            break;
        }
        draw();
    }
    */

}
