import java.util.*;

public class WordCount {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuilder inputBuilder = new StringBuilder();

        System.out.println("Enter words (type 'done' when finished): ");
        while (scanner.hasNextLine()) {
            String line = scanner.nextLine();
            if ("done".equalsIgnoreCase(line)) { break; }
            inputBuilder.append(line).append(" ");
        }
        scanner.close();

        String input = inputBuilder.toString().toLowerCase().replaceAll("[^a-z ]", "");
        String[] words = input.split("\\s+");

        Map<String, Integer> frequencyMap = new TreeMap<>();
        for (String word : words) {
            if (!word.isEmpty()) {
                frequencyMap.put(word, frequencyMap.getOrDefault(word, 0) + 1);
            }
        }

        System.out.println("Read " + (words.length - 1) + " words");

        for (Map.Entry<String, Integer> entry : frequencyMap.entrySet()) {
            if (!entry.getKey().equalsIgnoreCase("done")) {
                System.out.println(entry.getKey() + " : " + entry.getValue());
            }
        }

        frequencyMap.remove("done");
        if (!frequencyMap.isEmpty()) {
            String mostFrequentWord = Collections.max(frequencyMap.entrySet(),
                    Map.Entry.comparingByValue()).getKey();
            System.out.println("\"" + mostFrequentWord + "\" occurred " +
                    frequencyMap.get(mostFrequentWord) + " times");
        } else { System.out.println("No words were entered."); }
    }
}
