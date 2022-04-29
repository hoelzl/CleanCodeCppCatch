from pathlib import Path
import subprocess
import os


def find_vs_dir(working_dir:Path = Path()):
    working_dir = working_dir.absolute()
    if working_dir.name == "VS2017":
        vs_dir = working_dir
    elif working_dir.name == "Scripts":
        vs_dir = working_dir / "../VS2017"
    else:
        vs_dir = working_dir / "VS2017"

    vs_dir = vs_dir.resolve()
    assert vs_dir.exists(), f"VS2017 directory does not exist: {vs_dir}"
    assert vs_dir.name == f"VS2017", "VS2017 directory has bad name: {vs_dir}"
    return vs_dir

def run_cmake(working_dir:Path = Path()):
    vs_dir = find_vs_dir(working_dir)
    os.chdir(vs_dir)
    print(f"Working dir set to {os.getcwd()}.")
    print("Generating VS2017 solution.", flush=True)
    cp = subprocess.run(["cmake", "..", "-G", "Visual Studio 15 2017"])
    print(f"Task finished with return code {cp.returncode}.", flush=True)

if __name__ == "__main__":
    run_cmake()
    