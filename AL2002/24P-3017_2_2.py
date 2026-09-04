import random

class smartResponder:
    def __init__(self, name, responses):
        self.name=name
        self.responses=responses
        self.history=[]

    def respond(self, userInput):
        userInput=userInput.lower()
        self.history.append(userInput)

        for category, data in self.responses.items():
            keywords=data["keywords"]
            possibleResponses=data["responses"]

            for keyword in keywords:
                if keyword in userInput:
                    return random.choice(possibleResponses)

        return "Sorry, I don't understand."


SR = smartResponder("AunGPT", {
    "greeting": {
        "keywords":("hello", "hi", "greetings", "salutations"),
        "responses": ["Hello! I'm AunGPT!", "Hi there! I'm AunGPT, nice to meet you!", "Greetings! I'm AunGPT, how can I help?"]
    },

    "help": {
        "keywords": ("help", "assist", "support"),
        "responses": ["Sure! What do you need help with?", "I'm here to help!", "Tell me what you need assistance with."]
    },

    "exit": {
        "keywords": ("bye", "exit", "quit", "goodbye"),
        "responses": ["Goodbye!", "See you later!", "Thanks for chatting!"]
    }
})


print(f"I'm {SR.name}, Type something!")

while True:
    userInput=input("You: ")

    response=SR.respond(userInput)
    print(f"{SR.name}:{response}")

    exitKeywords=SR.responses["exit"]["keywords"]

    if any(keyword in userInput.lower() for keyword in exitKeywords):
        break


print("\nUser Input History:")
print(SR.history)