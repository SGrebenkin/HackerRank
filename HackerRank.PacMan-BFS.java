import java.awt.*;
import java.io.*;
import java.util.*;


public class Solution {

    public static boolean explore(int x, int y, int num, int[][] p, Queue q, ArrayList<StringBuilder> a, ArrayList<Point> s) {
        char c = a.get(y).charAt(x);
        if (c == '-' || c == 'P' || c == '.') {
            q.add(new Point(x, y));
            s.add(new Point(x, y));
            p[y][x] = num;
            if (c == '.')
                return false;
            a.get(y).setCharAt(x, 'e');
        }

        return true;
    }

    public static void done(int x, int y, ArrayList<StringBuilder> a) {
        char c = a.get(y).charAt(x);
        if (c == 'e')
            a.get(y).setCharAt(x, 'X');
    }

    public static void BFS(int pr, int pc, int fr, int fc, int rows, int clms, ArrayList<StringBuilder> a) {
        Queue q = new LinkedList();
        int[][] ids = new int[rows][clms];
        for (int j = 0; j < ids.length; ++j)
            for (int i = 0; i < ids[j].length; ++i)
                ids[j][i] = -1;

        ids[pr][pc] = 0;

        ArrayList<Point> exploredCells = new ArrayList<>();

        explore(pc, pr, 0, ids, q, a, exploredCells);

        while (q.size() > 0) {
            Point p = (Point) q.remove();
            int x = p.x;
            int y = p.y;
            int num = ids[y][x] + 1;

            if (x == fc && y == fr)
                break;

            if (!explore(x, y - 1, num, ids, q, a, exploredCells))
                break;

            if (!explore(x - 1, y, num, ids, q, a, exploredCells))
                break;

            if (!explore(x + 1, y, num, ids, q, a, exploredCells))
                break;

            if (!explore(x, y + 1, num, ids, q, a, exploredCells))
                break;

            done(x, y, a);
        }

        /*for (int i = 0; i < a.size(); ++i)
            System.out.println(a.get(i));*/
        System.out.println(exploredCells.size());
        for (int i = 0; i < exploredCells.size(); ++i)
            System.out.println(exploredCells.get(i).y + " " + exploredCells.get(i).x);

        /*for (int j = 0; j < ids.length; ++j) {
            for (int i = 0; i < ids[j].length; ++i)
                System.out.print(ids[j][i] + "\t");
            System.out.println();
        }*/

        // Find the way back
        Stack<Point> st = new Stack<>();
        int val = ids[fr][fc];
        int x = fc;
        int y = fr;
        st.push(new Point(x, y));
        while (val > 0) {
            if (ids[y + 1][x] == val - 1)
                y++;
            else if (ids[y][x + 1] == val - 1)
                x++;
            else if (ids[y][x - 1] == val - 1)
                x--;
            else if (ids[y - 1][x] == val - 1)
                y--;

            val--;
            st.push(new Point(x, y));
        }

        System.out.println(st.size() - 1);
        while (!st.empty())
            System.out.println(st.peek().y + " " + st.pop().x);
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int pr = in.nextInt();
        int pc = in.nextInt();

        int fr = in.nextInt();
        int fc = in.nextInt();

        int rows = in.nextInt();
        int clms = in.nextInt();

        in.nextLine();
        ArrayList<StringBuilder> arr = new ArrayList<>();
        for (int i = 0; i < rows; ++i)
            arr.add(new StringBuilder(in.nextLine()));

        BFS(pr, pc, fr, fc, rows, clms, arr);
    }
}
