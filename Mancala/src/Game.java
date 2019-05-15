import java.io.IOException;
import java.util.Scanner;

import java.io.InputStreamReader;


public class Game {

    private Board board;

    public Game(){
        board = new Board(6,2);

    }

    private void draw(){
        for(int i = 0; i < 20; i++){
            System.out.println();
        }

        board.draw();

    }

    public void run() throws IOException {
        Scanner in = new Scanner(System.in);

        while (true){
            this.draw();

            while(true){
                System.out.print("Player 1, Insert a column between 1 and 6:");
                int a = in.nextInt();

                if(board.moveFinished(1, a))
                    break;
            }

            while(true){
                System.out.print("Player 2, Insert a column between 1 and 6:");
                int b = in.nextInt();

                if(board.moveFinished(2,b));
                    break;

            }

        }

    }
}
