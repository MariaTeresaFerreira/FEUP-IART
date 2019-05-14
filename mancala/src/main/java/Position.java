public class Position {
    private int x;
    private int y;

    public Position(int x1, int y1){
        x = x1;
        y = y1;
    }

    public int getY() {
        return y;
    }

    public int getX() {
        return x;
    }

    public void setY(int y) {
        this.y = y;
    }

    public void setX(int x) {
        this.x = x;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;

        if (o == null) return false;

        if (getClass() != o.getClass()) return false;

        Position p = (Position) o;
        return x == p.getX() && y == p.getY();
    }

    @Override
    public String toString() {
        return "" + x + " " + y;
    }
}
