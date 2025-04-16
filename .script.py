import os

# Get the current working directory
cwd = os.getcwd()

# Loop through all files in the directory
for filename in os.listdir(cwd):
    # Check if the file ends with .exe
    if filename.endswith(".exe"):
        file_path = os.path.join(cwd, filename)
        try:
            os.remove(file_path)
            print(f"Deleted: {file_path}")
        except Exception as e:
            print(f"Error deleting {file_path}: {e}")
