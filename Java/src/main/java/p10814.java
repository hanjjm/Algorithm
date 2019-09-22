import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class p10814 {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int testCase = Integer.parseInt(br.readLine());
		Person[] person = new Person[testCase];

		for(int i = 0; i < testCase; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			person[i] = new Person(Integer.parseInt(st.nextToken()), st.nextToken(), i);
		}

		Arrays.sort(person, new Comparator<Person>() {
			@Override
			public int compare(Person o1, Person o2) {
				return Integer.compare(o1.age, o2.age);
			}
		});

		int j;
		for(int i = 0; i < testCase; i++) {
			for(j = i + 1; j < testCase; j++) {

				if(person[i].age != person[j].age) break;

			}
			Arrays.sort(person, i, j, new Comparator<Person>() {
				@Override
				public int compare(Person o1, Person o2) {
					return Integer.compare(o1.number, o2.number);
				}
			});

			i = j - 1;
		}


		for(int i = 0; i < testCase; i++) bw.write(person[i].age + " " + person[i].name + "\n");
		bw.close();
		br.close();

	}
}

class Person {
	int age, number;
	String name;

	Person (int age, String name, int number) {
		this.name = name;
		this.age = age;
		this.number = number;
	}
}
