public class Mancala extends Element {
    private Position position;
    private int score;

    public Mancala(int x1, int y1){
        super(x1,y1);

        position = new Position(x1,y1);   //atencao para criar antes de poder alterar
        score = 0;
    }

    public Mancala(int x1, int y1, int sc){
        super(x1,y1);

        position = new Position(x1,y1);   //atencao para criar antes de poder alterar
        score = sc;
    }

    public int getX() {
        return position.getX();
    }

    public int getY() {
        return position.getY();
    }

    public int getScore() {
        return score;
    }

    public void setX(int x) {
        position.setX(x);
    }

    public void setY(int y) {
        position.setY(y);
    }

    public void setScore(int score) {
        this.score = score;
    }

    public Position getPosition() {
        return position;
    }

    public void setPosition(Position position) {
        this.position = position;
    }

    @Override
    public String toString() {
        return  getX() + " "  + getY();
    }

    public void draw() {
        System.out.print(this.score);
    }
}