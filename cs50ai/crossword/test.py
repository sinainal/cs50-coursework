import generate
import crossword

crossword = crossword.Crossword("data/structure0.txt", "data/words0.txt")
creator = generate.CrosswordCreator(crossword)

#creator.order_domain_values(next(iter(crossword.variables)), {})
#creator.revise(list(crossword.variables)[1],list(crossword.variables)[2])
print(creator.test())
