import os
import random

class FileSearch:
    def __init__(self, directory, exclude_dirs=None):
        self.directory = directory
        self.exclude_dirs = exclude_dirs if exclude_dirs is not None else []

    def get_files_recursive(self):
        """
        Recursively get all files in a directory and its subdirectories.
        
        Returns:
        - list: A list of file paths found.
        """
        file_list = []
        for root, dirs, files in os.walk(self.directory):
            # Exclude directories listed in exclude_dirs
            dirs[:] = [d for d in dirs if d not in self.exclude_dirs]
            for file in files:
                file_path = os.path.relpath(os.path.join(root, file), self.directory)
                file_list.append(file_path)
        return file_list

    def get_random_file(self):
        """
        Get a random file from the list of files.
        
        Returns:
        - str: Path of a random file.
        """
        files = self.get_files_recursive()
        if files:
            return random.choice(files)
        else:
            return "No files found."

def main():
    root_directory = os.getcwd()  # Get the current directory
    exclude_dirs = [".git", ".vscode"]  # Add directories to exclude here
    
    file_search = FileSearch(root_directory, exclude_dirs)
    random_file = file_search.get_random_file()
    
    # Print the random file
    print(random_file)

if __name__ == "__main__":
    main()
