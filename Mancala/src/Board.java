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

    public boolean moveFinished(int player, int column){

        if(player == 1){
            int rocks = housesUp.get(column).getScore();
            housesUp.get(column).setScore(0);
            move(1,column, rocks);
        }
        else if( player == 2){
            int rocks = housesDown.get(column).getScore();
            housesDown.get(column).setScore(0);
            move(2,column, rocks);
        }
        return false;

    }

    private int move(int player, int column, int rocks){
        int finalPos = 0;
        for(int i = rocks; i > 0; i--){

        }
        return finalPos;
    }

    private void addRock(int player, int column){
        if(player == 1){
            housesUp.get(column).setScore(housesUp.get(column).getScore()+1);
        }
        else if( player == 2){
            housesDown.get(column).setScore(housesDown.get(column).getScore()+1);        }
    }
/*
    private int incrementPos(int line, int column){
        if(line == 2 && column == 6){
            return 16;
        }
        else if(line == 1 && column == 1){
            return 21;
        }

    }
*/

}
