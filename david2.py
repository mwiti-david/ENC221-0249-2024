class neighbour:
    def __init__(self,age,height,complexion,mood,name):
        self.name=name
        self.age=age
        self.height=height
        self.complexion=complexion
        self.mood=mood
    def results(self):
        return[f"my neighbour is {self.name}\n"
               
               f"my neighbour is {self.height} tall\n"
               
               f"my neighbour is {self.age} years old\n"
               
               f"my neighbour is {self.complexion}\n"

               f"my neighbour is {self.mood}\n"
               ]

        return
n1=neighbour(name="davis",age="20",height="5 foot",complexion="dark",mood="jovial")
for line in n1.results():
    print(line)

