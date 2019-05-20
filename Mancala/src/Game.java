import java.io.IOException;
import java.util.Scanner;

import java.io.InputStreamReader;
import java.util.Vector;


public class Game {

    private Board board;

    public Game(){
        board = new Board();

    }

    private void draw(){
        for(int i = 0; i < 10; i++){
            System.out.println();
        }

        board.draw();

    }

    public void run() throws IOException {
        Scanner in = new Scanner(System.in);

        while (!board.getGameOver()){
            this.draw();


            while (true){
                System.out.println("current board score: " + board.getBoardScore());
                System.out.println("Player 1, Insert the column you want to play between 1 and 6:");


                System.out.print("valid moves :");
                for(int i = 0; i < board.getValidMoves().size(); i++){
                    System.out.print(board.getValidMoves().get(i));
                }
                System.out.print("\n");
                System.out.print("valid moves size:");
                System.out.println(board.getValidMoves().size());

                int a = translateInput(in.nextInt(), board.getActivePlayer());
                if(board.move(0,a)) {
                    break;
                }
                draw();

            }

            this.draw();

            while (true){
                System.out.println("current board score: " + board.getBoardScore());
                System.out.println("Player 2, Insert the column you want to play between 1 and 6:");

                System.out.print("valid moves :");
                for(int i = 0; i < board.getValidMoves().size(); i++){
                    System.out.print(board.getValidMoves().get(i));
                }
                System.out.print("\n");
                System.out.print("valid moves size:");
                System.out.println(board.getValidMoves().size());

                int b = translateInput(in.nextInt(), board.getActivePlayer());
                if(board.move(1,b)){
                    break;
                }
                draw();
            }

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
