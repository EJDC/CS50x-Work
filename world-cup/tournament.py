# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    # filename is the 2nd command line argument
    filename = sys.argv[1]
    # open filename and call it f
    with open(filename) as f:
        #use dictreader function to read f
        reader = csv.DictReader(f)
        #loop through each row team
        for team in reader:
            #cast the rating of the team into an integer
            team["rating"] = int(team["rating"])
            #append the csv
            teams.append(team)



    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    # loop N times
    for i in range(N):
        #simulate tournament of teams and store winner
        winner = simulate_tournament(teams)
        #if winner already in counts, add one, otherwise set it to one.
        if winner in counts:
            counts[winner] +=1
        else
            counts[winner] = 1

    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    #loop through the teams until there's only one left
    while len(teams) > 1:
        #use simulate round function on the teams input, to get teams down to one
        teams = simulate_round(teams)
    #as there is only one team left (at spot 0 in the list), return it's name
    return teams [0]["team"]


if __name__ == "__main__":
    main()
