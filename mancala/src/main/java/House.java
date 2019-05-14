import com.googlecode.lanterna.SGR;
import com.googlecode.lanterna.TerminalPosition;
import com.googlecode.lanterna.TextColor;
import com.googlecode.lanterna.graphics.TextGraphics;

import java.util.Random;

public class House extends Element {
    private Position position;
    private int rocks;

    public House(int x1, int y1){
        super(x1,y1);
        position = new Position(x1,y1);   //atencao para criar antes de poder alterar
        rocks = 4;
    }

    public int getX() {
        return position.getX();
    }

    public int getY() {
        return position.getY();
    }

    public int getRocks() { return rocks; }

    public void setX(int x) {
        position.setX(x);
    }

    public void setY(int y) {
        position.setY(y);
    }

    public Position getPosition() {
        return position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }

    public void setRocks(int rocks) {
        this.rocks = rocks;
    }

    public Position move(){
        if(position.equals(new Position(1,1)))
            return new Position(1,2);
        else if(position.equals(new Position(6,2)))
            return new Position(6,1);
        else if(position.getY() == 1)
            return new Position(position.getX() - 1,1);
        else
            return new Position(position.getX() + 1,2);
    }

    @Override
    public String toString() {
        return  getX() + " "  + getY();
    }

    public void draw(TextGraphics graphics) {
        graphics.setForegroundColor(TextColor.Factory.fromString("#FFFF33"));
        graphics.enableModifiers(SGR.BOLD);
        graphics.putString(new TerminalPosition(position.getX(), position.getY()), String.valueOf(rocks));

        /*
        graphics.putString(new TerminalPosition(position.getX() * 2, position.getY() * 2), "\\/");
        graphics.putString(new TerminalPosition(position.getX() * 2, position.getY() * 2), "/\\");
        */

    }
}