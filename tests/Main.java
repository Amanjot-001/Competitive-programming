import java.util.*;

class Results {
    public String set_name;
    public List<String> selected_cards;

    public Results(String set_name, List<String> selected_cards) {
        this.set_name = set_name;
        this.selected_cards = selected_cards;
    }

    @Override
    public String toString() {
        return "Set: " + set_name + "\nCards: " + selected_cards.toString();
    }
}

class Solution {
    private static final List<String> RANK_ORDER = Arrays.asList("2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A");
    private static final List<String> SUIT_ORDER = Arrays.asList("C", "D", "H", "S");

    public Results solution(String[] cards) {
        Map<String, List<String>> rankMap = new HashMap<>();
        Map<String, List<String>> suitMap = new HashMap<>();

        // Fill the rank and suit maps
        for (String card : cards) {
            String rank = getRank(card);
            String suit = getSuit(card);

            rankMap.putIfAbsent(rank, new ArrayList<>());
            rankMap.get(rank).add(card);

            suitMap.putIfAbsent(suit, new ArrayList<>());
            suitMap.get(suit).add(card);
        }

        // Check for the strongest set in decreasing order of strength
        Results strongestSet = checkTripleAndPair(rankMap);
        if (strongestSet != null) return strongestSet;

        strongestSet = checkFiveInARow(rankMap);
        if (strongestSet != null) return strongestSet;

        strongestSet = checkSuit(suitMap);
        if (strongestSet != null) return strongestSet;

        strongestSet = checkTriple(rankMap);
        if (strongestSet != null) return strongestSet;

        strongestSet = checkPair(rankMap);
        if (strongestSet != null) return strongestSet;

        return checkSingleCard(rankMap);
    }

    private Results checkTripleAndPair(Map<String, List<String>> rankMap) {
        String tripleRank = null;
        String pairRank = null;
        for (String rank : RANK_ORDER) {
            if (rankMap.getOrDefault(rank, new ArrayList<>()).size() >= 3 && tripleRank == null) {
                tripleRank = rank;
            } else if (rankMap.getOrDefault(rank, new ArrayList<>()).size() >= 2 && pairRank == null) {
                pairRank = rank;
            }
        }

        if (tripleRank != null && pairRank != null) {
            List<String> cards = new ArrayList<>();
            cards.addAll(rankMap.get(tripleRank).subList(0, 3));
            cards.addAll(rankMap.get(pairRank).subList(0, 2));
            return new Results("a triple and a pair", cards);
        }

        return null;
    }

    private Results checkFiveInARow(Map<String, List<String>> rankMap) {
        List<String> consecutiveCards = new ArrayList<>();
        for (int i = 0; i < RANK_ORDER.size(); i++) {
            String rank = RANK_ORDER.get(i);
            if (rankMap.containsKey(rank)) {
                consecutiveCards.add(rankMap.get(rank).get(0));
                if (consecutiveCards.size() == 5) {
                    return new Results("five in a row", new ArrayList<>(consecutiveCards));
                }
            } else {
                consecutiveCards.clear();
            }
        }
        return null;
    }

    private Results checkSuit(Map<String, List<String>> suitMap) {
        for (String suit : SUIT_ORDER) {
            if (suitMap.getOrDefault(suit, new ArrayList<>()).size() >= 5) {
                return new Results("suit", suitMap.get(suit).subList(0, 5));
            }
        }
        return null;
    }

    private Results checkTriple(Map<String, List<String>> rankMap) {
        for (String rank : RANK_ORDER) {
            if (rankMap.getOrDefault(rank, new ArrayList<>()).size() >= 3) {
                return new Results("triple", rankMap.get(rank).subList(0, 3));
            }
        }
        return null;
    }

    private Results checkPair(Map<String, List<String>> rankMap) {
        for (String rank : RANK_ORDER) {
            if (rankMap.getOrDefault(rank, new ArrayList<>()).size() >= 2) {
                return new Results("pair", rankMap.get(rank).subList(0, 2));
            }
        }
        return null;
    }

    private Results checkSingleCard(Map<String, List<String>> rankMap) {
        for (int i = RANK_ORDER.size() - 1; i >= 0; i--) {
            String rank = RANK_ORDER.get(i);
            if (rankMap.containsKey(rank)) {
                return new Results("single card", Collections.singletonList(rankMap.get(rank).get(0)));
            }
        }
        return null;
    }

    private String getRank(String card) {
        return card.substring(0, card.length() - 1);
    }

    private String getSuit(String card) {
        return card.substring(card.length() - 1);
    }
}

public class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        
        String[] cards1 = {"2H", "4H", "7C", "9D", "10D", "KS"};
        String[] cards2 = {"AS", "10H", "8H", "10S", "8D"};
        String[] cards3 = {"AS", "JS", "AH", "AD", "10D", "AC"};
        String[] cards4 = {"6H", "7S", "8S", "9S", "10S", "JD", "JC", "KC", "AC"};
        String[] cards5 = {"2D", "4D", "6D", "8D", "9D", "AC", "KC", "QC", "JC", "7C"};
        String[] cards6 = {"10D", "10H", "10C", "2S", "2H", "2D", "JH", "JC"};

        System.out.println(solution.solution(cards1));
        System.out.println(solution.solution(cards2));
        System.out.println(solution.solution(cards3));
        System.out.println(solution.solution(cards4));
        System.out.println(solution.solution(cards5));
        System.out.println(solution.solution(cards6));
    }
}
