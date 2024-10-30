import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		char[][] mat = new char[n][n];
		for(int i = 0; i < n; i++)
			mat[i] = f.next().toCharArray();
		int cnt = 0;
		for(int i = 0; i < n-2; i++)
			for(int j = 0; j < n-2; j++)
				if(mat[i][j] == 'X' 
				&& mat[i+2][j] == 'X'
				&& mat[i+1][j+1] == 'X'
				&& mat[i][j+2] == 'X'
				&& mat[i+2][j+2] == 'X') cnt++;
		out.println(cnt);
		out.flush();
	}
    static class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }
    }
}