import java.io.IOException;


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

    public void run(){

        this.draw();

        //read imput and process it

    }
}
