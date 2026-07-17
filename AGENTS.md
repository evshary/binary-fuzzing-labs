# Repository Instructions

## Documentation

- Keep every README clear, concise, and easy for beginners to understand.
- Prefer short explanations and direct commands over long background sections.
- Keep examples small and focused on the concept taught by the lab.

## Lab Changes

When adding, removing, renaming, or reordering a lab, update all related files:

- Add or update the lab's Makefile.
- Update the root Makefile so its aggregate targets include the lab.
- Update the GitHub Actions CI workflow to build and validate the lab.
- Update the learning path in the root README.
- Update the `Next lab` section in affected lab READMEs.
- Update lab-specific `.gitignore` rules for generated files.

Keep each lab independently runnable from its own directory. Do not commit
generated binaries, fuzzing corpora, crash artifacts, or other build outputs.
