Excellent work, Asher — this is a clean, correctly functioning submission for a deceptively tricky challenge. You showed strong architectural thinking, API design, and safe coding practices. Let’s review your implementation interview-style:

# Scoring Breakdown

|Area               |Score  |	Comments                                                                                                                                                                |
|-------------------|-------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|Correctness	    | 5/5	|All operations (mkdir, addFile, readFile, snapshot, restore) work correctly. Terminal output reflects expected behavior.                                                   |
|OOP Design	        | 4.5/5	|File and FileSystem are modeled clearly. You respected encapsulation, used value semantics where appropriate. A FileSystemNode abstraction might improve extensibility.    |
|Smart Pointer Usage| 4/5	|std::shared_ptr<FileSystem> in main() is fine, but you didn't really need smart pointers at all — and you noted this. Correct instinct.                                    |
|API Clarity	    | 5/5	|Method names are intuitive, arguments are clean (const& used properly), return types (optional, bool) are idiomatic.                                                       |
|Memory Safety	    | 5/5	|All memory is stack-managed or copied safely. No raw pointers or leaks. Snapshot is deep-copied safely.                                                                    |
|Code Style	        | 5/5	|Emplace used properly, naming is clean, indentation is consistent. Printing logic is isolated nicely via operator<<.                                                       |
|Advanced Bonus	    | 4.5/5	|Snapshot functionality was implemented elegantly with deep copy of the map. You avoided shallow copies or dangling file references. Impressive!                            |


# What You Did Well

    Snapshot Restoration:
    You handled snapshots as deep copies (std::unordered_map<std::string, std::vector<File>>). This was crucial and cleanly done. No aliasing bugs.

    Filesystem API:
    You didn't overcomplicate it with a tree — that was the right call. Keys are string paths, and it’s plenty flexible.

    Use of STL:

        std::optional for readFile: 

        std::find_if for search: 

        emplace_back: 

        auto& and const&: 

    You Thought Critically About the Prompt:
    You challenged the smart pointer instruction and correctly decided not to force it into the wrong place. This is mature judgment.

# Suggestions (for Learning, not penalties)

    Operator Overloads:
    You overloaded operator<< for File, and for FileSystem. Great! One idea: in a larger project, consider making a toString() method inside File to isolate display logic from streaming.

    FileSystemNode (for later challenges):
    In real file trees, you might eventually introduce a Node base class with two subclasses: Directory and File, each with a name and maybe a parent. But for this challenge, your current flat model is perfect.

    Testing edge cases (for practice):
    Try adding files with same name, restoring a non-existent snapshot ID, or adding a file to an uncreated directory.

# Final Verdict

Score: 34.0 / 35

This is a professional-level submission with great structure, clarity, and precision. You made smart decisions where the brief was ambiguous and justified them well. 👏

You’re now ready for more complex file system or in-memory persistence challenges — and you’ve laid a solid foundation for real-world use of data structures like trees and snapshots.

Let me know if you'd like an optional stretch goal related to this, or if you're ready to start Day 8.

