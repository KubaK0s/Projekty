export module my_module;
import <iostream>;
import <fstream>;
import <filesystem>;



export void checkDiskSpace() {
    try {
        std::filesystem::path directoryPath = "C:/";
        std::filesystem::space_info spaceInfo = std::filesystem::space(directoryPath);
        uintmax_t freeSpace = spaceInfo.available;

        std::ofstream outputFile("output.txt");
        if (outputFile.is_open()) {
            outputFile << "Free space on drive C: " << freeSpace/(1024*1024*1024) << " GB" << std::endl;
            outputFile.close();
            std::cout << "The result was written to the output.txt file" << std::endl;
        }
        else {
            std::cout << "Failed to open file for writing" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << "An error occured: " << e.what() << std::endl;
    }
}