
import java.util.*;

public enum JavaDataBaseDictionary {

    //Contains all the enum in the database

    TEMP_ARROW_NOUN_SLOT1("arrow", "noun", "Here is one arrow: <IMG> -=>> </IMG>"),

    TEMP_DISTINCT_ADJECTIVE_SLOT1("distinct", "adjective", "Familiar. Worked with Java."),
    TEMP_DISTINCT_ADJECTIVE_SLOT2("distinct", "adjective", "Unique. No duplicates. Clearly different or of a different kind."),

    TEMP_DISTINCT_ADVERB_SLOT1("distinct", "adverb", "Uniquely. Written \"distinctly\"."),

    TEMP_DISTINCT_NOUN_SLOT1("distinct", "noun", "A Keyword in this assignment"),
    TEMP_DISTINCT_NOUN_SLOT2("distinct", "noun", "A Keyword in this assignment"),
    TEMP_DISTINCT_NOUN_SLOT3("distinct", "noun", "A Keyword in this assignment"),
    TEMP_DISTINCT_NOUN_SLOT4("distinct", "noun", "An advanced search option"),
    TEMP_DISTINCT_NOUN_SLOT5("distinct", "noun", "Distinct is a parameter in this assignment"),

    TEMP_PLACEHOLDER_ADJECTIVE_SLOT1("placeholder", "adjective", "To be updated. . ."),
    TEMP_PLACEHOLDER_ADJECTIVE_SLOT2("placeholder", "adjective", "To be updated. . ."),

    TEMP_PLACEHOLDER_ADVERB_SLOT1("placeholder", "adverb", "To be updated. . ."),

    TEMP_PLACEHOLDER_CONJUNCTION_SLOT1("placeholder", "conjunction", "To be updated. . ."),

    TEMP_PLACEHOLDER_INTERJECTION_SLOT1("placeholder", "interjection", "To be updated. . ."),

    TEMP_PLACEHOLDER_NOUN_SLOT1("placeholder", "noun", "To be updated. . ."),
    TEMP_PLACEHOLDER_NOUN_SLOT2("placeholder", "noun", "To be updated. . ."),
    TEMP_PLACEHOLDER_NOUN_SLOT3("placeholder", "noun", "To be updated. . ."),

    TEMP_PLACEHOLDER_PREPOSITION_SLOT1("placeholder", "preposition", "To be updated. . ."),

    TEMP_PLACEHOLDER_PRONOUN_SLOT1("placeholder", "pronoun", "To be updated. . ."),

    TEMP_PLACEHOLDER_VERB_SLOT1("placeholder", "verb", "To be updated. . ."),

    TEMP_CSC220_ADJECTIVE_SLOT1("csc220", "adjective", "Ready to create complex data structures."),

    TEMP_CSC220_VERB_SLOT1("csc220", "verb", "To create data structures."),

    TEMP_CSC340_ADJECTIVE_SLOT1("CSC340", "adjective", "= C++ version of CSC210 + CSC220 + more."),

    TEMP_CSC340_NOUN_SLOT1("csc340", "noun", "A CS upper division course."),
    TEMP_CSC340_NOUN_SLOT2("csc340", "noun", "Many hours outside of class."),
    TEMP_CSC340_NOUN_SLOT3("csc340", "noun", "Programming Methodology."),

    TEMP_BOOK_NOUN_SLOT1("book", "noun", "A set of pages."),
    TEMP_BOOK_NOUN_SLOT2("book", "noun", "A written work published in printed or electronic form."),

    TEMP_BOOK_VERB_SLOT1("book", "verb", "To arrange for someone to have a seat on a plane."),
    TEMP_BOOK_VERB_SLOT2("book", "verb", "To arrange something on a particular date."),

    TEMP_ADVERB_NOUN_SLOT1("adverb", "noun", "Adverb is a word that adds more information about place, time, manner, cause or degree to a verb, an adjective, a phrase or another adverb."),

    TEMP_ADJECTIVE_NOUN_SLOT1("adjective", "noun", "Adjective is a word that describes a person or thing, for example big, red and clever in a big house, red wine and a clever idea."),

    TEMP_INTERJECTION_NOUN_SLOT1("interjection", "noun", "Interjection is a short sound, word or phrase spoken suddenly to express an emotion. Oh!, Look out! and Ow! are interjections."),

    TEMP_NOUN_NOUN_SLOT1("noun", "noun", "Noun is a word that refers to a person, (such as Ann or doctor), a place (such as Paris or city) or a thing, a quality or an activity (such as plant, sorrow or tennis.");

    //The Variables inside the enum

    private static String[] tempSplitKeySearch;
    private String tempKeyword;
    private String tempPartOfSpeech;
    private String tempDefinition;

    //The Constructor that takes in 3 strings

    private JavaDataBaseDictionary(String tempKeyWord, String tempPartOfSpeech, String tempDefinition) {

        this.tempKeyword = tempKeyWord;
        this.tempPartOfSpeech = tempPartOfSpeech;
        this.tempDefinition = tempDefinition;
    }

    //Getters and setters

    public String getTempKeyword() {

        return tempKeyword;
    }

    public String getTempPartOfSpeech() {

        return tempPartOfSpeech;
    }

    public String getTempDefinition() {

        return tempDefinition;
    }

    public void setTempDefinition(String tempDefinition) {

        this.tempDefinition = tempDefinition;
    }

    public String toString() {

        return this.tempKeyword + " [" + this.tempPartOfSpeech + "] " + ": " + this.tempDefinition;
    }

    public static void main(String[] args) {

        System.out.println("! Loading data. . .");

        ArrayList<String> tempKeywordArrayList = new ArrayList<>();
        ArrayList<String> tempPartOfSpeechArrayList = new ArrayList<>();
        ArrayList<String> tempDefinitionArrayList = new ArrayList<>();

        for(JavaDataBaseDictionary tempValue: JavaDataBaseDictionary.values()) {

            String tempKeyword = tempValue.tempKeyword;
            String tempPartOfSpeech = tempValue.tempPartOfSpeech;
            String tempDefinition = tempValue.tempDefinition;

            tempPartOfSpeechArrayList.add(tempPartOfSpeech);
            tempKeywordArrayList.add(tempKeyword);
            tempDefinitionArrayList.add(tempDefinition);
        }

        Iterator<String> tempKeywordIterator = tempKeywordArrayList.iterator();
        Iterator<String> tempPartOfSpeechIterator = tempPartOfSpeechArrayList.iterator();
        Iterator<String> tempDefinitionIterator = tempDefinitionArrayList.iterator();

        System.out.println("! Loading completed. . .");

        System.out.println();
        System.out.println("-----DICTIONARY 340 JAVA-----");
        System.out.println();

        boolean tempStateQuit = false;

        Scanner tempUserInput = new Scanner(System.in);

        while(!tempStateQuit) {

            System.out.print("Search: ");

            String tempResult = tempUserInput.nextLine().toLowerCase();

            tempSplitKeySearch = tempResult.toString().split(" ");

            if(tempResult.equalsIgnoreCase("!q")) {
                tempStateQuit = true;
            }

            if(tempStateQuit) {

                System.out.println("\n-----THANK YOU-----");

                System.exit(0);
            }

            System.out.println("\t" + "|");

            if(!tempKeywordArrayList.contains(tempSplitKeySearch[0]) && tempSplitKeySearch.length < 2 && tempSplitKeySearch[0] != null) {

                displayTempNotFoundMessage();
            }

            else if (tempSplitKeySearch.length == 1) {

                while(tempKeywordIterator.hasNext() && tempPartOfSpeechIterator.hasNext() && tempDefinitionIterator.hasNext()) {

                    String result = tempKeywordIterator.next();
                    String result2 = tempPartOfSpeechIterator.next();
                    String result3 = tempDefinitionIterator.next();

                    if(result.equalsIgnoreCase(tempSplitKeySearch[0].toString())) {

                        displayFormatResult(result, result2, result3);
                    }

                }

                //Make the iterator for it to loop again once you reach here with split[] length = 1

                tempKeywordIterator = tempKeywordArrayList.iterator();
                tempPartOfSpeechIterator = tempPartOfSpeechArrayList.iterator();
                tempDefinitionIterator = tempDefinitionArrayList.iterator();

            }

            //If contains 2nd argument run this

            if(tempSplitKeySearch.length == 2 && tempSplitKeySearch[1] != null && !tempSplitKeySearch[1].equalsIgnoreCase("distinct") && (!tempPartOfSpeechArrayList.contains(tempSplitKeySearch[1]) || !tempKeywordArrayList.contains(tempSplitKeySearch[0]))  ) {
                
                displayTempNotFoundMessage();
            }

            //If contains "distinct" run this

            else if(tempSplitKeySearch.length == 2 && tempSplitKeySearch[1] != null && tempSplitKeySearch[1].equalsIgnoreCase("distinct") && tempKeywordArrayList.contains(tempSplitKeySearch[0])) {

                //Add only unique definitions

                Set<String> kevinSet = new LinkedHashSet<>();

                while(tempKeywordIterator.hasNext() && tempPartOfSpeechIterator.hasNext() && tempDefinitionIterator.hasNext()) {

                    String result = tempKeywordIterator.next();
                    String result2 = tempPartOfSpeechIterator.next();
                    String result3 = tempDefinitionIterator.next();

                    //Add into hash set the keyword entered by user

                    if(result.equalsIgnoreCase(tempSplitKeySearch[0].toString())) {

                        kevinSet.add(result + " [" + result2 + "] " + result3);
                    }
                }

                //loop through the hash set

                for(String tempDistinct: kevinSet) {
                    System.out.println("\t " + tempDistinct);
                }

                tempKeywordIterator = tempKeywordArrayList.iterator();
                tempPartOfSpeechIterator = tempPartOfSpeechArrayList.iterator();
                tempDefinitionIterator = tempDefinitionArrayList.iterator();
            }

            else if(tempSplitKeySearch.length == 2 && tempSplitKeySearch[1] != null && tempSplitKeySearch[1].equalsIgnoreCase("distinct") && (!tempPartOfSpeechArrayList.contains(tempSplitKeySearch[1]) || !tempKeywordArrayList.contains(tempSplitKeySearch[0]))) {

                displayTempNotFoundMessage();
            }

            //Run this if neither above is true

             else if(tempSplitKeySearch.length == 2) {

                Set<String> kevinSet = new LinkedHashSet<>();

                boolean matchResultDataBase = false;

                while(tempKeywordIterator.hasNext() && tempPartOfSpeechIterator.hasNext() && tempDefinitionIterator.hasNext()) {

                    String result = tempKeywordIterator.next();
                    String result2 = tempPartOfSpeechIterator.next();
                    String result3 = tempDefinitionIterator.next();

                    if(result.equalsIgnoreCase(tempSplitKeySearch[0].toString()) && result2.equalsIgnoreCase(tempSplitKeySearch[1].toString())) {

                        matchResultDataBase = true;

                        kevinSet.add(result + " [" + result2 + "] " + result3);

                        displayFormatResult(result, result2, result3);
                    }
                    else {
                        matchResultDataBase = false;
                    }
                }

                if(!matchResultDataBase && kevinSet.isEmpty()) {

                    displayTempNotFoundMessage();
                }

                tempKeywordIterator = tempKeywordArrayList.iterator();
                tempPartOfSpeechIterator = tempPartOfSpeechArrayList.iterator();
                tempDefinitionIterator = tempDefinitionArrayList.iterator();

            }

            //When 3 arguments

            if(tempSplitKeySearch.length > 2 && tempSplitKeySearch[1].equalsIgnoreCase("distinct") && tempSplitKeySearch[2].equalsIgnoreCase("distinct")) {

                if(!tempSplitKeySearch[0].equalsIgnoreCase("distinct")) {

                    displayTempNotFoundMessage();
                }
                else {
                    displayTempNotFoundMessage();
                }
            }

            else if(tempSplitKeySearch.length > 2 && (!tempPartOfSpeechArrayList.contains(tempSplitKeySearch[1])) ) {

                displayTempInvalidSecondArgument();
            }

            else if(tempSplitKeySearch.length > 2 && (!tempSplitKeySearch[2].equalsIgnoreCase("distinct") || !tempKeywordArrayList.contains(tempSplitKeySearch[0]) || !tempPartOfSpeechArrayList.contains(tempSplitKeySearch[1])) ) {

                displayTempNotFoundMessage();
            }

            else if(tempSplitKeySearch.length > 2 && tempSplitKeySearch[2].equalsIgnoreCase("distinct") && tempKeywordArrayList.contains(tempSplitKeySearch[0]) && tempPartOfSpeechArrayList.contains(tempSplitKeySearch[1])) {

                //System.out.println(tempSplitKeySearch[2]);

                Set<String> kevinSet = new LinkedHashSet<>();

                boolean matchResultDataBase = false;

                while(tempKeywordIterator.hasNext() && tempPartOfSpeechIterator.hasNext() && tempDefinitionIterator.hasNext()) {

                    String result = tempKeywordIterator.next();
                    String result2 = tempPartOfSpeechIterator.next();
                    String result3 = tempDefinitionIterator.next();

                    //Add into hash set the keyword entered by user

                    if(result.equalsIgnoreCase(tempSplitKeySearch[0].toString()) && result2.equalsIgnoreCase(tempSplitKeySearch[1])) {

                        matchResultDataBase = true;

                        kevinSet.add(result + " [" + result2 + "] " + result3);
                    }
                    else if(!result.equalsIgnoreCase(tempSplitKeySearch[0].toString()) || !result2.equalsIgnoreCase(tempSplitKeySearch[1])) {

                        matchResultDataBase = false;
                    }
                }

                //loop through the hash set

                for(String tempDistinct: kevinSet) {
                    System.out.println("\t " + tempDistinct);
                }

                //If the dataBase doesn't actually contain it, put not found

                if(!matchResultDataBase && kevinSet.isEmpty()) {
                    displayTempNotFoundMessage();
                }

                tempKeywordIterator = tempKeywordArrayList.iterator();
                tempPartOfSpeechIterator = tempPartOfSpeechArrayList.iterator();
                tempDefinitionIterator = tempDefinitionArrayList.iterator();

            }

            System.out.println("\t" + "|");

        }
    }

    private static void displayFormatResult(String tempKeyword, String tempPartOfSpeech, String tempDefinition) {

        System.out.println("\t " + tempKeyword + " [" + tempPartOfSpeech + "] " + tempDefinition);
    }


    private static void displayTempNotFoundMessage() {

        System.out.println("\t" + " <Not found>");

    }

    private static void displayTempInvalidSecondArgument() {

        System.out.println("\t" + " <2nd argument must be a part of speech or \"distinct\">");
    }

}






