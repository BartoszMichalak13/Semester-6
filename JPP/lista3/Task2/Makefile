# Java compiler
JAVAC = javac

# Java runtime
JAVA = java

# Main class
MAIN_CLASS = Main

# Classpath
# CLASSPATH = .:../../lista2/Task2/GF.java
# CLASSPATH = .:/home/bartek/Desktop/sem6/Semester-6/JPP/lista2/Task2/GF.java
# Source files
JAVA_FILES = GF.java DHSetup.java User.java Tests.java 
INTERFACES = IsGFlike.java ArithmeticOperations.java ByValueOperations.java Comparisons.java HasConstructorWithLongParam.java HasGetP.java IsGFlike.java
# Compile Java files 
compile:
	$(JAVAC) $(INTERFACES) $(JAVA_FILES)
# $(JAVAC) -cp $(CLASSPATH) $(JAVA_FILES)

# Run the program
# run:
# 	$(JAVA) -cp $(CLASSPATH) $(MAIN_CLASS)

# Clean compiled files
clean:
	rm -f *.class

# Phony targets
.PHONY: compile  clean
