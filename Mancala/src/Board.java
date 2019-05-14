import java.util.ArrayList;
import java.util.List;

public class Board {
    private int width;
    private int height;
    private List<Mancala> scores;
    private List<Mancala> housesUp;
    private List<Mancala> housesDown;



    public Board(int w, int h){
        width = w;
        height = h;

        this.scores = createScores();
        this.housesUp = createHouses(1);
        this.housesDown = createHouses(2);
    }

    private List<Mancala> createHouses(int line) {
        List<Mancala> houses = new ArrayList<>();

        for (int c = 1; c <= width; c++) {
                houses.add(new Mancala(c, line, 4));
        }
        return houses;
    }

    private List<Mancala> createScores() {
        List<Mancala> scores = new ArrayList<>();

        scores.add(new Mancala(0, 1, 0));
        scores.add(new Mancala(7, 2, 0));

        return scores;
    }


    public int getHeight() {
        return height;
    }

    public int getWidth() {
        return width;
    }

    public void setWidth(int width) {
        this.width = width;
    }

    public void setHeight(int height) {
        this.height = height;
    }
/*
    public void processKey(KeyStroke key){
        System.out.println(key);

        switch (key.getKeyType()){
            case F1:
                this.houses.get(2).setRocks( this.houses.get(2).getRocks() + 2 );
                break;

            case ArrowDown:
                break;

            case ArrowLeft:
                break;

            case ArrowRight:
                break;
        }

        if (key.getKeyType() == KeyType.Character && key.getCharacter() == 'q')
            System.out.println("letter q pressed");

    }
*/

    public void draw(){

        System.out.println();

        for (Mancala house : housesUp){
            System.out.print("  ");
            house.draw();
        }

        System.out.println();

        for (Mancala score : scores){
            score.draw();
            System.out.print("                  ");
        }

        System.out.println();

        for (Mancala house : housesDown){
            System.out.print("  ");
            house.draw();
        }

        System.out.println();


    }
}
