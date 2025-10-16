import glob

files = glob.glob("measurements[1-5].txt")

temperatures = []
with open("out.txt", "w") as out:
  out.write("Temp\tTime\n")
  for file in files:
    with open(file, "r") as f:
      for line in f:
        if line[:11] == "Temperature":
          line_sep = line.split(":")
          temp = float(line_sep[1].strip().split(" ")[0])
          time = float(line_sep[2].strip().split(" ")[0])

          out.write(f"{temp}\t{time}\n")
          temperatures.append(temp)

avg_temp = sum(temperatures) / len(temperatures)
print(f"Average temperature: {avg_temp} deg")
