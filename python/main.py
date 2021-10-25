import pandas as pd
import matplotlib.pyplot as plt
import colorsys
import subprocess


def run_chagapy():
    subprocess.run(["chagapy", "-g", "Unique", "-v", "5"])


def set_coloring(dataset):
    num_vertices = dataset["ref"].max() + 1
    delta = 1 / (num_vertices)

    dataset["color"] = ""
    dataset["dist"] = dataset["dist"] / dataset["dist"].max()

    for index, data in dataset.iterrows():
        hsv_color = (0.0 + data["ref"] * delta, -data["dist"] + 1, 1.0)
        dataset.at[index, "color"] = colorsys.hsv_to_rgb(*hsv_color)

    return dataset


def plot_data(dataset):
    fig, ax = plt.subplots(1, 1, figsize=(10, 10))
    fig.patch.set_facecolor((0.0, 0.0, 0.0))
    ax.set_facecolor((0.0, 0.0, 0.0))
    plt.axis("off")
    dataset.plot.scatter(x="x", y="y", ax=ax, s=0.1, c=dataset["color"])
    plt.show()


def main():
    run_chagapy()
    dataset = pd.read_csv("test.csv", names=["x", "y", "ref", "dist"])
    set_coloring(dataset)
    plot_data(dataset)


if __name__ == "__main__":
    main()
