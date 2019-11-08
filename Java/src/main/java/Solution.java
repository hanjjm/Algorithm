import java.util.Arrays;
import java.io.BufferedReader;
import java.io.InputStreamReader;

class Solution {
	public int solution(int[] d, int budget) {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int answer = 0;
		Arrays.sort(d);
		int tempBudget = 0;

		for(int i = 0; i < d.length; i++) {
			tempBudget += d[i];
			if(tempBudget > budget) break;
			answer++;
		}

		return answer;
	}
}
