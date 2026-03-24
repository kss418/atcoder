# AGENTS.md

## Scope

This file applies to everything under `atcoder/ABC/`.

## Directory Layout

- Contest folders use the pattern `<hundreds>/<tens>/<contest>/`.
- Examples:
  - `400/420/425/`
  - `300/390/399/`
  - `200/280/288/`
- The leaf folder name is the actual contest number and must match the README link.
- `Images/` is not a contest folder and should be ignored during contest-folder sweeps.

## Source File Placement

- Keep solution files inside the matching contest folder.
- Use the filename format `<Letter>_<Problem_Title>.cpp`.
- If new ABC solution files are sitting in the workspace root, move them into the correct contest folder under this tree.

## README Format

- Each contest folder should have a `README.md`.
- The first line must be:

```md
# https://atcoder.jp/contests/abc425/tasks
```

- Use one blank line between problem lines.
- Use this line format:

```md
A / Rating : $13$ / Implementation, Math
B / Rating : $82$ / Implementation, Greedy
C / Rating : $315$ / Prefix_Sum
```

- If a rating is unknown, use `$-$`.
- Use plain rating values only:

```md
$123$
$-$
```

- By default, list only the problems that actually have source files in that contest folder, unless the user asks for placeholders for unsolved problems.

## Image Rules

- Shared ABC images live directly under `ABC/Images/`.
- Use the filename format `<contest>.png`.
- Do not create or reuse `ABC/Images/Standings/` or `ABC/Images/Performance/`.
- If a contest README includes an image, keep it after the problem list.
- Use a single standings image only.
- Use this image line format:

```md
![My Image](https://github.com/kss418/Atcoder/blob/main/ABC/Images/425.png)
```

## Tagging Rules

- Tags should reflect the actual solution code, not just the official problem category.
- Prefer repository-style spellings already used often in this tree.
- Common normalized tags:
  - `Implementation`
  - `Case_Work`
  - `Math`
  - `Strings`
  - `Greedy`
  - `Prefix_Sum`
  - `BFS`
  - `DFS`
  - `Dijkstra`
  - `Graphs`
  - `DP`
  - `Combinatorics`
  - `Bitmasks`
  - `Segment_Tree`
  - `Priority_Queue`
  - `Lazy_Propagation`
  - `Disjoint_Set`
  - `Geometry`
  - `Simulation`
  - `Randomization`
  - `Divide_And_Conquer`
  - `Inclusion-Exclusion_Principle`

- Prefer these normalized names over inconsistent variants:
  - `Bitmasks` instead of `Bitmasks_DP`
  - `Lazy_Propagation` instead of `Segment_Tree` when the main technique is a lazy segment tree
  - `Geometry` instead of `CCW`
  - `Divide_And_Conquer` instead of `DnC`
  - `Inclusion-Exclusion_Principle` instead of `In-Ex Principle`

## New Contest Workflow

1. Compute the target contest folder from the contest number.
2. Create the folder if it does not exist.
3. Move the solved source files into it.
4. Create or update `README.md`.
5. Use `$-$` for ratings that are still unknown.
6. Fill tags based on the actual code.
7. Verify that:
   - filenames are correct
   - the README link matches the folder number
   - the README uses plain ratings

## Existing Contest Cleanup

When normalizing older contests in this tree:

1. Check whether the README link matches the folder number.
2. Normalize ratings to `$number$` or `$-$`.
3. Update tags only when the current tag is clearly inconsistent with the solution code or repository style.
4. Preserve everything else unless the user asks for broader cleanup.
