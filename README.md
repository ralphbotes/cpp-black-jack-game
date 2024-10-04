# Simple Blackjack Game

### Objective
The goal is to have cards that total as close to 21 as possible without going over (busting).

### Card Values
- Number cards (2-10) are worth their face value.
- Face cards (Jack, Queen, King) are each worth 10 points.
- Aces can be worth either 1 or 11 points, depending on which is more favorable to the player.

### Gameplay
The game is usually played between the player and the dealer. Both the player and the dealer start with two cards:
- The player’s cards are face-up.
- The dealer has one face-up card and one face-down card (the "hole" card).

The player can choose to:
- **Hit**: Take another card.
- **Stand**: Keep their current total and end their turn.
- **Double Down**: Double their bet and take exactly one more card.
- **Split**: If the player's first two cards have the same value, they can split them into two separate hands.

### Winning
- The player wins by having a hand value higher than the dealer's without going over 21 or if the dealer busts (goes over 21).
- A **Blackjack** (Ace + 10-value card) on the first two cards beats any other hand.

---

## Key Components You'll Need to Implement

### Card Deck
- A deck of 52 cards.
- Functions to shuffle and deal cards.
- Represent each card as a structure or class with a suit and value.

### Player and Dealer
- Classes or structures to represent the player and dealer.
- Each has a hand (a collection of cards) and methods to draw cards, check their total, and determine whether to hit or stand.

### Game Flow
- Initial card dealing (two cards for both the player and the dealer).
- **Player’s turn**: Allowing the player to hit, stand, or double down.
- **Dealer’s turn**: Dealer must hit if their total is below 17 and stand otherwise.
- End of round: Compare hands and determine the winner.

### Aces Handling
- Implement logic to treat an Ace as 1 or 11, depending on the situation, to prevent unnecessary busts.

### Betting System (Optional)
- You can add a simple betting system where the player can wager, and the dealer or player pays based on who wins.

### User Interface
- A text-based input/output for simplicity, allowing the player to see their hand and choose actions like hitting or standing.

---

## Structure of the Program

### Card Class/Struct:
- **Suit**: (Hearts, Spades, etc.)
- **Rank**: (2-10, Jack, Queen, King, Ace)
- **Value**: (Derived from rank)

### Deck Class:
- **List of cards**
- **Shuffle method**
- **Deal method**: Returns a card

### Player Class:
- **Hand**: (List of cards)
- Functions to calculate hand value, hit, and stand.

### Game Logic:
- Deal cards.
- Player decision-making.
- Dealer logic: Hitting until 17 or higher.
- Check for busts and determine the winner.

---

## Tips

- **Modularity**: Keep the code modular by separating classes for cards, players, and game logic.
- **Testing**: Test the game frequently as you build. Start by dealing cards and calculating hand totals before adding the full game flow.
- **Edge cases**: Handle edge cases like multiple Aces, splitting hands, or both the player and dealer busting.

