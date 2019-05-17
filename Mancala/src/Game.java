import java.io.IOException;
import java.util.Scanner;

import java.io.InputStreamReader;


public class Game {

    private Board board;

    public Game(){
        board = new Board();

    }

    private void draw(){
        board.draw();

    }

    public void run() throws IOException {
        Scanner in = new Scanner(System.in);

        while (!board.getGameOver()){
            int player = board.getActivePlayer() + 1;
            System.out.println("Player " + player + " Insert a column between 1 and 6:");

            this.draw();
            int a = in.nextInt();
            board.move(board.getActivePlayer(), a);
            board.nextPlayer();




/*
            while(true){
                System.out.print("Player 1, Insert a column between 1 and 6:");


                if(board.moveFinished(1, a))
                    break;
            }

            while(true){
                System.out.print("Player 2, Insert a column between 1 and 6:");
                int b = in.nextInt();

                if(board.moveFinished(2,b));
                    break;

            }
            */


        }

    }
}
