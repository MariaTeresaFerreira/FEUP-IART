import java.util.*;

public class Board {
    public static final int N_PLAYERS = 2;
    public static final int N_STONES = 4;
    public static final int N_PITS = 6;

    private int[] mancalas;
    private int[][] pits;
    private int activePlayer;
    private Boolean gameOver;

    public Board(){
        pits = new int[N_PLAYERS][N_PITS];
        mancalas = new int[N_PLAYERS];
        activePlayer = 0;
        gameOver = false;

        for (int p = 0; p < N_PLAYERS; p++)
        {
            mancalas[p] = 0;

            for (int col = 0; col < N_PITS; col++)
                pits[p][col] = N_STONES;
        }
    }

    public int[] getMancalas() {
        return mancalas;
    }

    public int[][] getPits() {
        return pits;
    }

    public int getActivePlayer() {
        return activePlayer;
    }

    public Boolean getGameOver() {
        return gameOver;
    }

    public void setMancalas(int[] mancalas) {
        this.mancalas = mancalas;
    }

    public void setPits(int[][] pits) {
        this.pits = pits;
    }

    public void setActivePlayer(int activePlayer) {
        this.activePlayer = activePlayer;
    }

    public void setGameOver(Boolean gameOver) {
        this.gameOver = gameOver;
    }

    public void draw(){

        System.out.println();

        for (int i = N_PITS - 1; i >= 0; i--){
            if(pits[0][i] < 10)
                System.out.print("  ");
            else
                System.out.print(" ");
            System.out.print(pits[0][i]);
        }

        System.out.println();

        for (int i = 0; i < N_PLAYERS; i++){
            System.out.print(mancalas[i]);
            if(mancalas[i] < 10)
                System.out.print("                  ");
            else
                System.out.print("                 ");

        }

        System.out.println();

        for (int i = 0; i < N_PITS; i++){
            if(pits[1][i] < 10)
                System.out.print("  ");
            else
                System.out.print(" ");
            System.out.print(pits[1][i]);
        }

        System.out.println();
    }

    public boolean move(int side, int pit){

        if (side != activePlayer)
            return false;

        if (pits[side][pit] == 0)
            return false;

        int rocks = pits[side][pit];
        pits[side][pit] = 0;

        while (rocks > 0){

            pit = nextPit(pit);

            if(pit == 0){

                if(side == activePlayer){
                    mancalas[side] += 1;
                    rocks -= 1;

                    if(rocks == 0){
                        checkEmpty();

                        return false;
                    }
                }
                side = nextSide(side);
            }
            pits[side][pit] += 1;
            rocks -= 1;
        }
        turnEnd(side, pit);

        return true;
    }

    private int nextPit(int pit)
    {
        pit += 1;
        if (pit == N_PITS)
            pit = 0;
        return pit;
    }

    private int nextSide(int side)
    {
        side += 1;
        if (side == N_PLAYERS)
            side = 0;
        return side;
    }

    private void endGame(int side)
    {
        gameOver = true;

        for (int i = 0; i < N_PITS; i++) {
            mancalas[side] += pits[side][i];
            pits[side][i] = 0;
        }
    }

    private void checkEmpty() {

        int empty;
        for (int i = 0; i < N_PLAYERS; i++)
        {
            empty = 0;
            for (int j = 0; j < N_PITS; j++)
            {
                if (pits[i][j] == 0)
                    empty++;
            }

            if (empty == N_PITS)
            {
                endGame(nextSide(i));
                break;
            }
        }
    }

    private void turnEnd(int side, int pit){

        if (side == activePlayer && pits[side][pit] == 1){
            mancalas[side] += 1 + pits[nextSide(side)][N_PITS - pit - 1];
            pits[side][pit] = 0;
            pits[nextSide(side)][N_PITS - pit - 1] = 0;
        }

        activePlayer = nextSide(activePlayer);

        checkEmpty();
    }

    public int getBoardScore(){
        return mancalas[0] - mancalas[1];
    }



    public Vector<Integer> getValidMoves(){
        Vector<Integer> validPlays = new Vector<>();
        if(this.getActivePlayer() == 1){
            for(int i = 1; i < 7 ; i++){
                if(pits[this.getActivePlayer()][i-1] != 0)
                    validPlays.add(new Integer(i));
            }
        } else if(this.getActivePlayer() == 0){
            if(pits[this.getActivePlayer()][5] != 0){
                validPlays.add(new Integer(1));
            }if(pits[this.getActivePlayer()][4] != 0){
                validPlays.add(new Integer(2));
            }if(pits[this.getActivePlayer()][3] != 0){
                validPlays.add(new Integer(3));
            }if(pits[this.getActivePlayer()][2] != 0){
                validPlays.add(new Integer(4));
            }if(pits[this.getActivePlayer()][1] != 0){
                validPlays.add(new Integer(5));
            }if(pits[this.getActivePlayer()][0] != 0){
                validPlays.add(new Integer(6));
            }
        }

        return validPlays;
    }

}
