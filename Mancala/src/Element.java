public abstract class Element {
    private Position position;

    public Element(int x1, int y1){

        this.position = new Position(x1,y1);
    }

    @Override
    public String toString(){
        return position.toString();
    };

    public abstract void draw();
}