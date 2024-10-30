public class MyPoint {
    private int x;
    private int y;

    public MyPoint() {
        this.x = 0;
        this.y = 0;
    }

    public MyPoint(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int[] getXY() {
        return new int[]{x, y};
    }

    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }

    public double distance(int x, int y) {
        int xDiff = this.x - x;
        int yDiff = this.y - y;
        return Math.sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    public double distance(MyPoint another) {
        int xDiff = this.x - another.x;
        int yDiff = this.y - another.y;
        return Math.sqrt(xDiff * xDiff + yDiff * yDiff);
    }

    public double distance() {
        return Math.sqrt(x * x + y * y);
    }

    public static void main(String[] args) {
        MyPoint point1 = new MyPoint();
        System.out.println("Point 1: " + point1);
        MyPoint point2 = new MyPoint(3, 4);
        System.out.println("Point 2: " + point2);
        point1.setXY(5, 6);
        System.out.println("Point 1 after setXY(): " + point1);
        int[] coordinates = point2.getXY();
        System.out.println("Point 2 coordinates: (" + coordinates[0] + ", " + coordinates[1] + ")");
        System.out.println("Distance between Point 1 and (5, 6): " + point1.distance(5, 6));
        System.out.println("Distance between Point 1 and Point 2: " + point1.distance(point2));
        System.out.println("Distance from Point 1 to origin: " + point1.distance());
    }
}