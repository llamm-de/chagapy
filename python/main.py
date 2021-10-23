import pandas as pd
import matplotlib.pyplot as plt
import colorsys


def main():
    print("Loading data...")
    dataset = pd.read_csv("test2.csv", names=["x", "y", "ref", "dist"])

    print("Set coloring...")
    num_vertices = dataset["ref"].max() + 1
    delta = 1 / (num_vertices)

    dataset["color"] = ""
    dataset["dist"] = dataset["dist"] / dataset["dist"].max()

    for index, data in dataset.iterrows():
        hsv_color = (0.0 + data["ref"] * delta, -data["dist"] + 1, 1.0)
        dataset.at[index, "color"] = colorsys.hsv_to_rgb(*hsv_color)

    print("Creating plot...")

    fig, ax = plt.subplots(1, 1, figsize=(10, 10))
    fig.patch.set_facecolor((0.0, 0.0, 0.0))
    ax.set_facecolor((0.0, 0.0, 0.0))
    plt.axis("off")

    dataset.plot.scatter(x="x", y="y", ax=ax, s=0.1, c=dataset["color"])

    plt.show()


if __name__ == "__main__":
    main()