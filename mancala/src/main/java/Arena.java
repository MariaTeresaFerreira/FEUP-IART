import com.googlecode.lanterna.graphics.TextGraphics;
import com.googlecode.lanterna.input.KeyStroke;
import com.googlecode.lanterna.input.KeyType;

import java.util.ArrayList;
import java.util.List;

public class Arena {
    private int width;
    private int height;
    private List<Score> scores;
    private List<House> houses;


    public Arena(int w, int h){
        width = w;
        height = h;

        this.scores = createScores();
        this.houses = createHouses();
    }

    private List<House> createHouses() {
        List<House> houses = new ArrayList<>();

        for (int c = 1; c <= width; c++) {
            for (int r = 1; r <= height; r++) {
                houses.add(new House(c, r));
            }
        }
        return houses;
    }

    private List<Score> createScores() {
        List<Score> scores = new ArrayList<>();

        scores.add(new Score(0, 1));
        scores.add(new Score(7, 2));

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

    public void processKey(KeyStroke key){
        System.out.println(key);

        switch (key.getKeyType()){
            case ArrowUp:
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


    public void draw(TextGraphics graphics){

        for (Score score : scores)
            score.draw(graphics);

        for (House house : houses)
            house.draw(graphics);

    }
}
