#Anna Park word game
#pseudocode: #create a define word list: words{Food:[],Artists:[],Sports:[]}
#2. create the Menu Page and different functions including menu{}.
#def Menu page include: 1. instructions, 2.Guessing Sports 3. Guessing Food 4. Guessing Artist 3. Play Game, 4. scoreboard, 5. Exit
    #running = True
    # choice = input(choose an option:)
    # if choice = x for each of the options and this is connected to their own function pages
    #scoreboard: print("Score: calculating_score")
        #input("Would you like to save this in a file? Yes or no?"),
        #if y or yes, user_nameinput(what is your name?) / with open("scoreboard.txt", "a") as file: file.write("{player_name}: {score}")
    #if choice == 5
        #print("Exiting the game, hope to see you soon. Goodbye!")
        #running = False
#def instructions() - using print() function, explain how the game will function to the player, input(do you understand?), brings user back to the main menu
#def word_selection() - brings user to a page with three different options
    #print("1. Play with a 3-letter word"), print("2. Play with a 4-letter word"), print("3. Play with a 5-letter word")
    #input(Choose an option) -> brings user back to the main menu
#def play_game() - random chooses the word from the defined word list,
    #attempts = word_length -1, print("you have ___ attempts")
    #while attempts > 0 input("enter your guess")
        #if the user inputs a letter and if the letter exists in the word, print("Correct! The letter exists in the word.")
        #if the user inputs a word and it is correct, print("Congratulations! You've guessed the word correctly.")
        #else("Incorrect guess.") and print("___ attempts remaining")
        # when the attempts == 0, print("The word was '___'.") and brings the user back to the main menu
        #if correct_guess:points += 7 if guess in 'aeio' else 10

import random
word_choices = {
    'sport':['tennis', 'basketball', 'baseball', 'soccer', 'softball', 'volleyball', 'badminton', 'wrestling', 'golf', 'football', 'boxing', 'swim', 'dive', 'waterpolo', 'running','ice hockey','fencing', 'dance', 'cheer','curling'],
    'food':['hamburger', 'steak', 'burrito', 'taco', 'ramen', 'poke', 'pasta', 'pizza', 'panini', 'sushi', 'waffle', 'salad', 'rice', 'curry', 'paella', 'dumplings','ice cream','mac and cheese','aparagus','crossiant'],
    'artist':['sza', 'taylor swift', 'harry styles', 'ariana grande', 'drake', 'madison beer', 'tate mcrae', 'sabrina carpenter', 'olivia rodrigo', 'baby keem', 'kanye west', 'daniel caesar', 'doja cat', 'bad bunny', 'jack harlow', 'kendrick lamar', 'pink sweats', 'summer walker', 'adele', 'justin bieber', 'travis scott']
}

def print_menu(): #https://extr3metech.wordpress.com/2014/09/14/simple-text-menu-in-python/
        print("+" + "-" * 38 + "+")
        print("|" + " " * 14 + "Game Menu" + " " * 15 + "|")
        print("+" + "-" * 38 + "+")
        print("| 1. Instructions" + " " * 22 + "|")
        print("| 2. Guess Sport" + " " * 23 + "|")
        print("| 3. Guess Food" + " " * 24 + "|")
        print("| 4. Guess Artist" + " " * 22 + "|")
        print("| 5. Scoreboard" + " " * 24 + "|")
        print("| 6. Exit" + " " * 30 + "|")
        print("+" + "-" * 38 + "+")

def instructions():
    print("Hi, welcome to the Word Game!")
    print("Here, you will be playing a game or games of guessing words in different categories of your choice!")
    print("The game is simple, you have a limited amount of attempts. Guess the letter wisely and carefully.")
    print("There are three different categories of game available: Guessing Sport, Guessing Food, and Guessing Artist.")
    print("Before exiting, you can save your score as a file and compare your score with others! ")
    y = input("Do you want to go back to the main screen? (yes/no) ")
    if y == "yes" or y == "y":
        main()
    else:
        instructions()

def guess_game(category):
    word = random.choice(word_choices[category]) #https://www.w3schools.com/python/ref_random_choice.asp
    guessed = [' ' if char == ' ' else '_' for char in word]
    attempts = 5
    points = 0
    print(f" Welcome to Guessing {category.capitalize()}!")
    print("Guess the word by typing one letter at a time.")
    print(" ".join(guessed)) #https://www.w3schools.com/python/ref_string_join.asp

    while attempts > 0 and '_' in guessed:
        guess = input("Guess a letter: ").lower() #automatically making the input lowercase like the dicitonary https://www.w3schools.com/python/python_ref_string.asp
        if len(guess) == 1 and guess.isalpha(): # checking if it is alphabet https://www.w3schools.com/python/python_ref_string.asp
            if guess in word:
                correct_guess = False #initial val
                for i in range(len(word)):
                    if word[i] == guess and guessed[i] == '_':  # Update only if not already guessed
                        guessed[i] = guess
                        correct_guess = True # changed to True
                if correct_guess:
                    points += 7 if guess in 'aeio' else 10
                    print("Correct guess:", " ".join(guessed))
                else:
                    print("Letter already guessed:", " ".join(guessed))
            else:
                attempts -= 1
                print(f"Wrong choice. {attempts} attempts remaining.")
        else:
            print("Invalid input, please enter a single letter.")
        print(f"Current points: {points}")
    if '_' not in guessed:
        print(f"Congratulations! You've guessed the word '{word}' and finished with {points} points.")
    else:
        print(f"Game over! The word was '{word}'. You finished with {points} points.")

    return points

import csv
def save_score(point, user_name): #saving scores to a file
        with open("scoreboard.csv", "a", newline = '') as file:
                writer = csv.writer(file)
                writer.writerow([user_name ,point])#https://www.freecodecamp.org/news/how-to-create-a-csv-file-in-python/
        print(f"Score has been saved for {user_name}: {point} points.\n")# Using f-string for formatting #https://www.freecodecamp.org/news/python-print-variable-how-to-print-a-string-and-variable/

def display_scoreboard(): #idea from the class sharing activity (16 Feb 2024)
    try:
        with open("scoreboard.csv", "r") as file:
            reader = csv.reader(file)
            scores = sorted(reader, key = lambda x: int(x[1]), reverse = True)
        print("Top Scores:")
        for name, score in scores[:10]:  # Display top 10 scores
            print(f"{name}: {score}")
    except FileNotFoundError:
        print("Scoreboard is empty.")

    ye = input("Do you want to go back to the main screen? (yes/no) ")
    if ye == "yes" or ye == "y":
        main()
    else:
        display_scoreboard()

def main():
    while True:
        print_menu()
        screen = input("Enter which menu you want to go to (1-6): ")
        if screen == '1':
            instructions()
        elif screen in ['2', '3', '4']:
            if screen == '2':
                category = 'sport'
            elif screen == '3':
                category = 'food'
            else:
                category = 'artist'
            point = guess_game(category)
            user_name = input("What is your name? ")
            save_score(point, user_name)
        elif screen == '5':
                display_scoreboard()
        elif screen =='6':
            print("Exiting the game, hope to see you soon. Goodbye!")
            break

if __name__ == "__main__":
    main()
    #Python script is a common idiom used to check whether the script is being run as the main program or not. / or else my program doesn't finish
    #https://realpython.com/if-name-main-python/
