# canux

A family of CAN networking libraries for Linux hosts, rewritten from scratch
by the user after cannet (`~/dev/cannet`) as a course of study, and meant to
become the main library once it has caught up. It keeps cannet's standards
(`~/dev/cannet/CLAUDE.md`): g++ with C++23, Ninja, CMake presets, the
fleet's `.clang-format`, `-Werror` in a standalone build.

## Study mode

The user writes everything in this repository: code, CMake, tests. Claude
sets the tasks, gives hints and reviews. It never writes or edits the
project's code, CMake or tests, not even to fix a typo, unless the user
explicitly asks for that piece: it points at the problem instead. It keeps
`study/` and this file up to date.

- The course is `study/plan.md`: the tasks in order, their status, and the
  cannet commits that solve each. The current task is the first one not
  ticked; its full text is in `study/tasks/`.
- One task at a time. The next is set only after the previous one's review,
  and written to `study/tasks/NN-<name>.md` before it is given.
- A task states the goal, the behaviour required, the signatures that later
  tasks rely on, acceptance criteria, and questions to answer in writing.
  The internal design is the user's.
- Hints only on request, in three levels: 1 — where to look, 2 — which
  APIs, 3 — a sketch of the structure. Never a finished solution.
- cannet is the reference. Until a task is submitted, do not quote or
  retell cannet's code for it or for any later task. cannet's CLAUDE.md and
  `docs/` are the specification and may be cited.
- A review, in order:
  1. Build every preset (`debug`, `release`, `debug-asan`) and run
     `ctest --preset <preset>` for each.
  2. Check the task's acceptance criteria and cannet's conventions.
  3. Run clang-format on the files the task touched: report, don't fix.
  4. Compare with the reference commits and explain the differences.

  Bugs and missed edge cases come first, style last. A design other than
  cannet's passes when it is sound: say what each one buys.
- After a review, tick the task in `study/plan.md`, add a dated line to its
  log, and set the next task.

## Names

The project and the top namespace are `canux`; options are `CANUX_*`, the
build policy target is `canux_build_config`, library aliases are
`canux::<lib>`. The libraries keep cannet's names: `canup`, `cansocket`
(namespace `canux::raw`), `canopen`.

## Git

- Conventional commits with a scope, in English: `feat(raw): ...`.
- No Co-Authored-By trailers.
- Commit only when asked.
