# Challenge: Filesystem Snapshots

# Scenario:
You’re designing a snapshotting system for a simplified filesystem. It tracks files and directories, their structure, and allows capturing the state of the filesystem at a point in time. Later, you can restore to that snapshot.

## Requirements:

You must implement a system that supports:

    mkdir(path) — creates directories along the path.

    addFile(path, content) — adds a file with string content at the path.

    readFile(path) — returns the content at the given file path.

    snapshot() — captures the current state of the filesystem.

    restore(snapshot_id) — restores the filesystem to the state of the given snapshot.

## Design Constraints:

    Paths will be like: /a/b/c.txt or /docs/notes.md.

    Each snapshot should be assigned a unique ID (starting from 0).

    Snapshots are deep copies: if the user modifies the FS after snapshotting, the old snapshot stays unchanged.

    Use appropriate classes: File, Directory, FileSystem, etc.

    You may design your own internal tree representation.

## Example:

FileSystem fs;

fs.mkdir("/a/b");
fs.addFile("/a/b/file.txt", "hello world");
fs.snapshot(); // snapshot 0

fs.addFile("/a/b/notes.md", "another file");
fs.snapshot(); // snapshot 1

fs.restore(0);
fs.readFile("/a/b/file.txt"); // returns "hello world"
fs.readFile("/a/b/notes.md"); // error or nullopt

## Goal:

    Aim for 45 minutes.

    Focus on modularity, smart pointers, clean class design.

    Don’t worry about persistence or actual disk I/O.

    You do not need to implement command parsing — just classes and APIs.
