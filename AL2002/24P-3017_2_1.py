# image_shape=(224, 224, 3)
# width, height, channels=image_shape
# print(f"image : {width}x{height},  {channels} channels")

# def evaluate_model(predictions, actual):
#     correct=sum(1 for p, a in zip(predictions, actual) if p==a)
#     print(correct)
#     total=len(actual)
#     accuracy=correct/total
#     return correct, total, accuracy

# predictions=[1, 0, 1, 1, 0]
# truth=[1, 0, 0, 1, 0]

# correct, total, acc=evaluate_model(predictions, truth)
# print(f"Accuracy: {correct}/{total} = {acc:.0%}")

# class KnowledgeBase:
#     def __init__(self):
#         self.facts={}

#     def tell(self, key, value):
#         self.facts[key]=value
#         print(f"Learned: {key}={value}")

#     def ask(self, key):
#         return self.facts.get(key, "I don't know")
    
#     def size(self):
#         return len(self.facts)
    
# kb=KnowledgeBase()
# kb.tell("capital of pakistan", "Islamabad")
# kb.tell("pi", 3.142)
# kb.tell("python_creator", "Guido van Rossum")

# print(kb.ask("capital of pakistan"))
# print(kb.ask("meaning of life"))
# print(f"Knowledge base currently stores {kb.size()} facts")

# class AIModel:
#     model_count=0

#     def __init__(self, name, accuracy):
#         self.name=name
#         self.accuracy=accuracy
#         AIModel.model_count+=1

#     def display(self):
#         print(f"{self.name}: {self.accuracy:.0%} accuracy")

# m1=AIModel("Spam Filter", 0.95)
# m2=AIModel("Image Classifier", 0.89)
# m3=AIModel("Chatbot", 0.78)

# m1.display()
# m2.display()
# print(f"Total models created: {AIModel.model_count}")

# class Agent:
#     def __init__(self, name):
#         self.name=name
#         self.actions_taken=0

#     def act(self, action):
#         self.actions_taken+=1
#         print(f"[{self.name}] Action: {action}")

# class ReflexAgent(Agent):
#     def __init__(self, name, rules):
#         super().__init__(name)
#         self.rules=rules

#     def decide(self, percept):
#         action=self.rules.get(percept, "do nothing")
#         self.act(action)

# thermostat=ReflexAgent("Thermostat", {
#     "hot": "cooldown",
#     "cold": "heat up",
#     "normal": "do nothing"
# })

# thermostat.decide("hot")
# thermostat.decide("cold")
# thermostat.decide("normal")
# print(f"Total actions: {thermostat.actions_taken}")

class Dataset:
    def __init__(self, name, data):
        self.name=name
        self.data=data

    def __str__(self):
        return f"Dataset '{self.name}' ({len(self.data)} samples)"
    
    def __getitem__(self, idx):
        return self.data[idx]
    
iris=Dataset("Iris", [[5.1, 3.5], [4.9, 3.0], [7.0, 3.2]])

print(iris)
print(len(iris))
print(iris[0])
print(iris[-1])
